/*
Name: Matthew Schroder
CSCI 3110-001
Project 6
Due: Mon, Apr 1
Purpose: Declares the wordtree object, reads the input string, converts it to all lowercase,
         takes each word and stores it in an element of "words" vector. Iterates through the 
         vector calling addWord for each element. It then reads from the query and performs 
         the appropriate task via findWord() and getCounts()
*/

#include "wordtree.h" 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

void split(const string&, char, vector<string>&);

int main()
{
   WordTree tree;
   ifstream myfile;
   int toFind;                      //the number of desired counts
   string text = " ", newword, fstring;        //The full text and the string of interest
   char delimiter = ' ', query;     //Delimiter for split func and the Query choice
  
    
   myfile.open("input.txt"); 
   while(!myfile.eof())         //Reads until end of file
   {
   myfile >> newword;               //Sets string that is to be added to the text string
   text = text + " " + newword; //adds the new word to the current text
   }
   myfile.close();

   std::transform(text.begin(), text.end(), text.begin(), ::tolower);  //Transforms string to lowercase
   
   vector<string> words;
   vector<string>::iterator it;

   split(text,delimiter,words);     //Splits the string into a vector of words
 
   for(it = words.begin(); it!=words.end(); it++)       //Loops through the vector sending a reference of the it pointer to addword for each el
   {
    tree.addWord(*it);
   }

   cout << "Word tree built and loaded\n\n";

   myfile.open("queries.txt");

   myfile >> query;     //primer for eof condition
   while(!myfile.eof()) 
   {
           //Starts process to find the desired word
           if(query == 'F')
           {
                   myfile >> fstring;
                   cout << "Searching for occurrences of the word '" << fstring << "'\n"; 
                   tree.findWord(fstring);
           }
           //Starts process to get count of words past a certain threshold 
           else if(query == 'C')
           {
                   myfile >> toFind;
                   cout << "Finding all words with " << toFind << " or more occurences:\n"; 
                   tree.getCounts(toFind);
           }
           
           myfile >> query;
   }

   myfile.close();

   return 0;
}

void split(const std::string& s, char c, std::vector<std::string>& v)
{

std::string::size_type i = 0;
std::string::size_type j = s.find(c);

while (j != std::string::npos) 
    {
    v.push_back(s.substr(i, j-i));
    i = ++j;
    j = s.find(c, j);
    if (j == std::string::npos)
       v.push_back(s.substr(i, s.length()));
    }
}
