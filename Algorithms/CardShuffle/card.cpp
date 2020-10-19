//Matthew Schroder
//CSCI 3110-001
//Project 7
//04/15/2019
//Overloads the << >= and <= for the card object, and sets is face and suit

#include "card.h"
#include <iomanip>

//Default constructor 
Card::Card(){}

Card::Card(int face, suit st)
{
  cardFace = face;
  cardSuit = st;
}


//Outputs the member variables of a card class
ostream& operator<<(ostream& os, const Card& cd)
{
        switch(cd.cardFace)
        {
          case 1: os << 'A';break;
          case 2: os << '2';break;
          case 3: os << '3';break;
          case 4: os << '4';break;
          case 5: os << '5';break;
          case 6: os << '6';break;
          case 7: os << '7';break;
          case 8: os << '8';break;
          case 9: os << '9';break;
          case 10: os << '1' << '0';break;
          case 11: os << 'J';break;
          case 12: os << 'Q';break;
          case 13: os << 'K';break;
        }
        if(cd.cardSuit == 0)
                os << 'C';
        if(cd.cardSuit == 1)
                os << 'H'; 
        if(cd.cardSuit == 2)
                os << 'S';
        if(cd.cardSuit == 3)
                os << 'D';

        os << "[" << cd.cardFace << "] "; 
  return os;
}


//returns the card's face
int Card::getFaceValue() const
{
  return cardFace;
}

//returns the card's suit
suit Card::getSuit() const
{
  return cardSuit;
}

bool Card::operator <= (const Card& rhs) const
{
        if(this-> cardFace <= rhs.cardFace)
                return true;
        else
                return false;
}

bool Card::operator >= (const Card& rhs) const
{
        if(this-> cardFace >= rhs.cardFace)
                return true;
        else
                return false;
}
