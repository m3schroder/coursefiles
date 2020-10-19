//Matthew Schroder
//CSCI 3110-001
//Project 7
//04/15/2019
//Declares the queue objects and the card object arrays that are used in them. Calls the enqueue and dequeue functions
//for the min and max queues

#include "priorityqueue.h"
#include "card.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std; 

int main()
{
    int seed, i; 

    ifstream myfile;
    myfile.open("pqseed.txt");
     
    myfile >> seed; 
    srand(seed);
   
    PriorityQueue <Card,  GreaterThan<Card> > maxQueue;
    PriorityQueue <Card, LessThan <Card> > minQueue;
    
    Card *newCard; 
    Card HD[13];
    for(i = 0; i < 13; i++)
    {
            newCard = new Card(i+1, hearts);
            HD[i] = *newCard;
    }
    
    Card SD[13];
    for(i = 0; i < 13; i++)
    {
            newCard = new Card(i+1, spades);
            SD[i] = *newCard;
    }
    
    std::random_shuffle(std::begin(SD), std::end(SD));
    std::random_shuffle(std::begin(HD), std::end(HD));
    
    //Handles the maxqueue for the spade deck
    for(i = 0; i < 13; i++)
    {
        maxQueue.enqueue(SD[i]);
        cout << "Enqueued "<< SD[i];
        maxQueue.print();
        cout << endl;
    }
    
    cout << "\n";

    for(i = 0; i < 13; i++)
    {
        maxQueue.dequeue();
        maxQueue.print();
        cout << endl;
    }
   
    if(maxQueue.empty() == true)
            cout << "Max Heap Empty\n\n";

   
    //Handles the minqueue for the hearts deck
    for(i = 0; i < 13; i++)
    {
        minQueue.enqueue(HD[i]);
        cout << "Enqueued "<< HD[i];
        minQueue.print();
        cout << endl;
    }
    
    cout << "\n";

    for(i = 0; i < 13; i++)
    {
        minQueue.dequeue();
        minQueue.print();
        cout << endl;
    }
   
    if(minQueue.empty() == true)
            cout << "Min Heap Empty\n\n";

	return 0;
}




