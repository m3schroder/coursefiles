/*
Name: Matthew Schroder
CSCI 3110-001
Project 6
Due: Mon, Apr 1
Purpose: This file provides the implementation of the public and private member functions as well as the constructor and destructor
*/

#include "wordtree.h"

//Calls the private member function addWord that has access to root
void WordTree::addWord(string s)
{
    addWord(root,s);       
}

//The recursive helper function that can access root, it recurses through the tree adding words to appropriate null nodes
void WordTree::addWord(TreeNode *& node, string s)             
{
  if(node != NULL)
  {
   if(s < node->value)      //move left because the curr nodes value is greater than s
           addWord(node->left,s);

   else if(s > node->value) //move right because the curr nodes value is less than s
           addWord(node->right,s);

   else if(s == node->value)    //Increase the counter because value is equal to s
           node->count++; 
  }
  else
  {
          node = new TreeNode;
          node->value = s;
          node->left = NULL;
          node->right = NULL;
          node->count = 1;
  }
}

//Recursive function that appropriately deallocates all of the word trees nodes  
void WordTree::deleteSubTree(TreeNode * node)
{
         if (node == NULL) 
            return; 
                           
         // first recur on left subtree 
         deleteSubTree(node->left); 
          
         // then recur on right subtree 
         deleteSubTree(node->right); 
                                               
         // now deal with the node 
         delete node; 
}
        

//Recursive helper function that returns the count and value of words past a threshold 
void WordTree::getCounts(TreeNode * node, int thresh, int& acc) const
{
        
       if(node == NULL) 
               return;
       //moves through the left side then goes back up
       getCounts(node->left, thresh, acc);

       if(node->count >= thresh)
       {
               cout << node->value << "(" << node->count << ")" <<endl;
               acc++;
       }
       //moves through the right side then goes back up      
       getCounts(node->right,thresh,acc);
               
}
                                                           
//Driver side function to get word counts 
void WordTree::getCounts(int thresh)
{
        int acc = 0;
        getCounts(root, thresh, acc);   //calls the recursive getCounts function
        cout << acc << " nodes had words with " << thresh << " or more occurence(s).\n\n";
       
}

//Function that finds a certain word, or tries to, and returns its count
void WordTree::findWord(string s)
{
        bool found = false;
        stack<TreeNode*> stack;
        TreeNode * node = root;
        
        while(node!=NULL || stack.empty() == false)     
        {
               while(node != NULL)      
               {
                       //Pushes nodes from root to far left onto the stack 
                       stack.push(node);
                       //Moves left through the tree 
                       node = node->left;
               }
               
               node = stack.top();
               //Pops of the node on top of the stack or the last node added
               stack.pop();

               //If node->value == s print the word and its count, set found equal to true if not already
               if(node->value == s)
               {
                       cout << "The word '" << s << "' occurs " << node->count << " time(s) in the text\n\n";
                       if(found == false)
                               found = true;
                       return;
               }
                       
               node = node->right;
        }
        
        if(found == false)
               cout << "The word '" << s << "' was not found in the text.\n\n"; 

            
}

//Initializes the root node of the word tree
WordTree::WordTree()    
{
   root = new TreeNode; 
   root->left = NULL; 
   root->right = NULL; 
   root->value = " ";
   root->count = 0;
}

WordTree::~WordTree()
{
        deleteSubTree(root);
}

   
   



