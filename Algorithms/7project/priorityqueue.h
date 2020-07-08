//Matthew Schroder
//CSCI 3110-001
//Project 7
//04/15/2019
//Defines the functions necessary to manipulate and maintain a priority queue, contains the definition and declaration for comparators
//as well the heapUp and heapDown functions that are called by enqueue and dequeue

#ifndef PRIORITY_H
#define PRIORITY_H

#include <vector>
#include <iterator>
#include <iostream>
#include "card.h"
#include <iomanip>

using namespace std;
  
template<typename item, typename comp>
class PriorityQueue 
{
    
    private:
   
    //keeps up with the size of the number of el in the vector 
    int size = 0;
        
    vector<item> vec;

    //Heaps item up based on priority                    
    void heapUp(int child)
    {
            Card hold;
            comp comparator;
            int parent = (child - 1)/2;

        while(child > 1 && comparator.compare(vec[child], vec[parent]) == true)
        {
               //The size of the tree minus the location (child) is equal to the index location of the item 
               //the same is true for the parent node
               swap(vec[child], vec[parent]);
               
               //Changes where the parent node is
               child = parent;
               //Finds the parent node for the new child node
               parent = (child-1) / 2;
        }             
     }
            
    //Heaps item down based on priority                    
    void heapDown(int parent)
    {
           int lc = (2*parent) + 1;
           int rc = (2*parent) + 2;
           comp comparator;

           //Exits the instance if both child are NULL (aka its a leaf) 
           if(lc > size - 1){}

           //Only checks left child and parent if right child doesnt exist
           else if(rc > size - 1 )
           {
                  if(comparator.compare(vec[lc], vec[parent]) == true)
                  {
                          swap(vec[lc], vec[parent]);
                          heapDown(lc);
                  }
           }

           //Checks left and right child to see which is bigger if any
           else
           {
                   if(comparator.compare(vec[lc], vec[rc]) == true)
                   {
                           if(comparator.compare(vec[lc], vec[parent]) == true)
                           {
                                   swap(vec[lc], vec[parent]);
                                   heapDown(lc);
                           }
                   }
                   if(comparator.compare(vec[rc], vec[lc]) == true)
                   {
                           if(comparator.compare(vec[rc], vec[parent]) == true)
                           {
                                   swap(vec[rc], vec[parent]);
                                   heapDown(rc);
                           }
                   }

           }
     }
   
    public:
    
    //Resizes the vector to have 50 elements 
    PriorityQueue()
    {
            vec.reserve(50);
    }

    //Removes the highest priority item 
    void dequeue()
    {
            cout << "Dequeued " << vec[0] << " ";
            swap(vec[0], vec[size -1]);
            vec.pop_back();
            size--;
            heapDown(0);
    }

    //Enqueues item based on its priority in the heap
    void enqueue(item toEn)
    {
            vec.push_back(toEn);
            size++;
            heapUp(size - 1);
    }

    //Displays all items in the heap
    void print()
    {
            for(int i = 0; i < size; i++)
            {
                    cout << vec[i] << " ";
            }
    }

    //Returns true if the queue is empty
    bool empty()
    {

        if(size == 0)
            return true;
        else 
            return false;
           
    }
                       
};
#endif

template<typename T1>
class GreaterThan
{
        public:
            bool compare(const T1& lhs, const T1& rhs) const
            {
                    return (lhs >= rhs);
            }
};

template<typename T1>
class LessThan
{
        public:
            bool compare(const T1& lhs, const T1& rhs) const
            {
                    return (lhs <= rhs);
            }
};
