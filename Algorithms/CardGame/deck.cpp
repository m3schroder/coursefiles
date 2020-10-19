#include "deck.h"
#include <algorithm>

using std::cout;
using std::endl;
using std::random_shuffle;

Deck::Deck()
{

topCard = 51;

Card *newCard;
for(int i = 0; i < 52; i++)
     {
           if(i >= 0 && i < 13)
               {   
                    int face = 12 - i; 
                    newCard = new Card(face, diamonds);                      
                    theDeck[i] = *newCard;
               }

           else if(i > 12 && i < 26)
               {
                    int face = 12 - (i-13); 
                    newCard = new Card(face, spades);                    
                    theDeck[i] = *newCard;
               }

           else if(i > 25 && i < 39)
               {
                    int face = 12 - (i-26);
                    newCard = new Card(face, hearts);
                    theDeck[i] = *newCard;
               }

           else  if(i > 38 && i < 52)
               {
                    int face = 12 - (i-39); 
                    newCard = new Card(face, clubs);
                    theDeck[i] = *newCard;
               }

           delete newCard ;                      
     }
}


//Deals the top card of the deck variable and subtracts one from the topcard variable
Card Deck::dealCard()
{
    //makes a variable top of Card type that is the current "topCard" index
    Card top = theDeck[topCard];

    //Increments the topCard whenever a card is delt
    topCard--;

    //returns the Card variable top to be dealt
    return top;
}

//shuffles "theDeck"
void Deck::Shuffle()
{    
    Card newDk[52]; 
    for(int i = 0; i < 52; i++)
     {
             newDk[i] = theDeck[i];
     }
    
    for(int i = 0; i < 52; i++)
     {
             theDeck[51-i] = newDk[i];
     }
    random_shuffle(std::begin(theDeck),std::end(theDeck));
}

//topCard has gone past element 52 of theDeck array and the deck is now empty
bool Deck::isEmpty()
{
  if(topCard >=0)
  return 0;

  else
  return 1;
}

//Prints each individual card of the deck and orders them by suit
ostream& operator << (ostream& os, const Deck& deck)
{
   if(deck.theDeck[0].getPointValue() == 10 && deck.theDeck[0].getSuit() == 3 && deck.theDeck[0].getFaceValue() == 12)
   {
     for(int i = 0; i < 52; i++)
     {
        //creates a new row for each suit
        if(i%13 == 0 && i !=0)
          cout << endl;
        
        cout << deck.theDeck[i];
     }
   }
  
   else
   {
    for(int i = 51; i >=0; i--)
     {
        //creates a new row for each suit
        if(i%13 == 0 && i !=0)
          cout << endl;
        
        cout << deck.theDeck[i];
     }
   }
    cout << endl;
    return os;
}
