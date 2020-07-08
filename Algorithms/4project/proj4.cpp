#include "card.h"
#include "deck.h"
#include "player.h"
#include "stdlib.h"
#include <fstream>

using namespace std;

int main()
{
     ifstream myFile;
     myFile.open("cardgame.txt");
     string name1;
     string name2;
     int seed;
     myFile >> name1;
     myFile >> name2;
     myFile >> seed;
     
     srand(seed);
     Player Spongebob(name1);
     Player Squidward(name2);
     Deck dk;   
     
     cout << dk << endl;
     dk.Shuffle();
     cout << dk << endl; 
     
     //Draw 3 cards to start with                
     for(int i = 0; i < 3; i++)
     {
     Spongebob.drawCard(dk);
     Squidward.drawCard(dk);
     }
   
     //Play for 26 rounds when all cards are out of the deck 
     for(int i = 1; i < 27; i++) 
  {
     
     cout << i << ") Spongebob "<< Spongebob << " -  Squidward " << Squidward << endl;
     
     //Store rvalue from play card into new card variables
     Card play1 = Spongebob.playCard();
     Card play2 = Squidward.playCard();
     
     //If the play1 card has a higher point value then p1 wins and the card is added to the score       
     if(play1.getPointValue() > play2.getPointValue())
     {
          Spongebob.addScore(play1);
          Spongebob.addScore(play2);
          cout << i << ") Spongebob* "<< Spongebob << " -  Squidward " << Squidward << endl;
     }

     //If the play2 card has a higher point value then p2 wins and the card is added to the score       
     else if(play1.getPointValue() < play2.getPointValue())
     {
          Squidward.addScore(play1);
          Squidward.addScore(play2);
          cout << i << ") Spongebob "<< Spongebob << " -  Squidward* " << Squidward << endl;
     }

     //No one wins in the tie only the names and played cards are displayed 
     else 
          cout << i << ") Spongebob " << Spongebob << " - " << "Squidward " << Squidward << endl;
    
     cout << endl;
    
     if(dk.isEmpty() == false)
     {
     Spongebob.drawCard(dk);
     Squidward.drawCard(dk);
     }
     else
     cout << endl;
  }

     //It is now the end of the game either a winner is delcared or a tie  followed by the score
     if(Spongebob.getScore() > Squidward.getScore())
             cout << "Winner Spongebob " << Spongebob.getScore() << endl;

     else if(Spongebob.getScore() < Squidward.getScore())
             cout << "Winner Squidward " << Squidward.getScore() << endl;

     else
             cout << "Tie " << Spongebob.getScore() << endl;
             
            
  return 0;
}
