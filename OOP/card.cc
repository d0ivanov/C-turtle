#include<iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

class Card{
	
	private: 
		
		string suit_;
	 	string value_;
	
	public:
		
		string getSuit(){
			return suit_;
		}
		
		void setSuit(string suit){
			suit_ = suit;
		}
		
		string getValue(){
			return value_;
		}
		
		void setValue(string value){
			value_ = value;
		}
		
		void print(Card card){
			cout << card.getSuit() << " " << card.getValue() << endl;
		}
};

class Deck{
	private:
		Card deck_[52];
		
		int generateRand(){
			srand((unsigned)time(0)); 
   		 	int random_integer; 
        	random_integer = (rand()%51)+1;   		 	 
		}
	
	public:
		
		Deck(){
		string suits[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
		string values[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "A", "J", "Q", "K"};
			for(int i = 0; i < 13; i++){
				deck_[i].setSuit(suits[0]);
				deck_[i].setValue(values[i]);
				
				deck_[i+1].setSuit(suits[1]);
				deck_[i+1].setValue(values[i]);
				
				deck_[i+2].setSuit(suits[2]);
				deck_[i+2].setValue(values[i]);
				
				deck_[i+3].setSuit(suits[3]);
				deck_[i+3].setValue(values[i]);
			}
		}
		
		Card at(int i){
			return deck_[i];
		}
		
		void shuffle(){
			for(int i = 0; i < 52; i++){
				int j = generateRand();
				Card temp = deck_[i];
				deck_[i] = deck_[j];
				deck_[j] = temp;
			}
		}
};

int main(){
	Deck deck;
	Card card;
	deck.shuffle();
	card.print(deck.at(1));

	return 0;	
}
