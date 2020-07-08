#include "player.h"

Player::Player(string n)
{
  name = n;
  score = 0;
  hasPlayed[0] = true;
  hasPlayed[1] = true;
  hasPlayed[2] = true;
}


Card Player::playCard()
{
//check the easiest way first   
       if(hand[0] > hand[1] && hand[0] > hand[2]){
        hasPlayed[0] = true;
        return hand[0];} 
       
       else if(hand[1] > hand[0] && hand[1] > hand[2]){
        hasPlayed[1] = true;
        return hand[1];} 
       
   
       else{
        hasPlayed[2] = true;
        return hand[2];} 

//if 0 == 1   
        if(hand[0].getPointValue() == hand[1].getPointValue() && hand[0].getPointValue() > hand[2].getPointValue())
        {
                if(hand[0].getFaceValue() == hand[1].getFaceValue())
                {
                        if(hand[0].getSuit() < hand[1].getSuit()){
                                hasPlayed[0] = true;
                                return hand[0];}
                        else{
                                hasPlayed[1] = true;
                                return hand[1];}
                }
                else if(hand[0].getFaceValue() > hand[1].getFaceValue()){
                        hasPlayed[0] = true;
                        return hand[0];}
                else{
                        hasPlayed[1] = true;
                        return hand[1];}
        }
//if 0 == 2
        if(hand[0].getPointValue() == hand[2].getPointValue() && hand[0].getPointValue() > hand[1].getPointValue())
        {
                if(hand[0].getFaceValue() == hand[2].getFaceValue())
                {
                        if(hand[0].getSuit() < hand[2].getSuit()){
                                hasPlayed[0] = true;
                                return hand[0];}
                        else{
                                hasPlayed[2] = true;
                                return hand[2];}
                }
                else if(hand[0].getFaceValue() > hand[2].getFaceValue()){
                        hasPlayed[0] = true;
                        return hand[0];}
                else{
                        hasPlayed[2] = true;
                        return hand[2];}
        }
//if 1 == 2        
        if(hand[2].getPointValue() == hand[1].getPointValue() && hand[2].getPointValue() > hand[0].getPointValue())
        {
                if(hand[2].getFaceValue() == hand[1].getFaceValue())
                {
                        if(hand[2].getSuit() < hand[1].getSuit()){
                                hasPlayed[2] = true;
                                return hand[2];}
                        else{
                                hasPlayed[1] = true;
                                return hand[1];}
                }
                else if(hand[2].getFaceValue() > hand[1].getFaceValue()){
                        hasPlayed[2] = true;
                        return hand[2];}
                else{
                        hasPlayed[1] = true;
                        return hand[1];}
        }      
       
           
}

//This function needs some more thought
void Player::drawCard(Deck& dk)
{
   if(hasPlayed[0] == true)
   {
     hand[0]=dk.dealCard();
     hasPlayed[0] = false;
     return;
   }
   else if(hasPlayed[1] == true)
   {
     hand[1]=dk.dealCard();
     hasPlayed[1] = false;
     return;
   }
   else if(hasPlayed[2] == true)
   {
     hand[2]=dk.dealCard();
     hasPlayed[2] = false;
     return;
   }
   else 
     return; 
}

//Adds the total player score to the score of acard
void Player::addScore(Card acard)
{
    score = score + acard.getPointValue();
}

int Player::getScore() const
{
  return score;
}

string Player::getName() const
{
  return name;
}

bool Player::emptyHand() const
{
  if((hasPlayed[0]||hasPlayed[1]||hasPlayed[2])== 0)
    return true;

  else
    return false;
}

ostream& operator << (ostream& os, const Player& player)
{
    for(int i = 0; i < 3; i++)
    {
      if(player.hasPlayed[i] == false)
          os << player.hand[i];
      else
          os << " _____ ";
    }
    os << '(' << player.score << ')';
    return os;
}
