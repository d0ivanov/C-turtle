(ns web-crawler2.core)
(use 'web-crawler2.soup)
(use 'clojure.java.io 'clojure.string)

(defn get-links [page] 
  ($ (get! page) td "a[href]" (attr "abs:href")))

(defn write-to-hf [st append] ;write to hash.txt file
  (with-open [wrtr (writer "hash.txt" :append append)]
    (.write wrtr st)))

(defn crawl [source current-depth max-depth]
  (if (= current-depth 0) (write-to-hf "{" false))
  (let [targets (get-links source)]
    (write-to-hf (str ":" source " " (vec (map keyword targets)) "\n") true)
    (if (< current-depth max-depth)
      (doall (map crawl targets (repeat (inc current-depth)) (repeat max-depth)))
      (if (= current-depth 0)
        (do (write-to-hf "}" true)
         targets)
        targets))))

(defn read-hash-unique []
  (->> (slurp "hash.txt")
        (re-seq #"[^{} \n]+")
       (partition 2)
       (map vec)
       (into {})))

(defn get-unique-elements [hashmap]
  (distinct (flatten (for [x hashmap] (x 1)))))

(defn in? [seq target]  
  (some #(= target %) seq))

(defn distance [src target h] 
  (if (= src target)
    0
    (when (h src)
      (if (in? (h src) target)
        1
        (let [arr (filter #(not= % nil) (map #(distance % target h) (h src)))]
          (when-not (empty? arr) 
            (inc (apply min arr))))))))

(defn main [index max-depth]
  (crawl index 0 max-depth)
  (let [unique-elements (set (get-unique-elements (read-hash-unique)))]
    (distance index :http://www.bard.bg/genres/?id=1 unique-elements)))
