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
		(write-to-hf (str ":" source " " (seq targets) "\n") true)
		(if (< current-depth max-depth)
			(map crawl targets (repeat (inc current-depth)) (repeat max-depth))
			(if (= current-depth 0)
				(do (write-to-hf "}" true)
				 targets)
				targets))))

(defn read-hash-unique []
	(into {}
  		(with-open [r (reader "hash.txt")]
	 		(doall (distinct
				(map #(read-string
					(str "[" (trim (replace % #"[{}]" "")) "]"))
						(line-seq r)))))))
