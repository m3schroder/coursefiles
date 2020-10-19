#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
from classes import Node, PriorityQueue, State, Set
from functions import h

if (len(sys.argv) != 2):
    sys.exit(1)

# The objective function parses out the state and check whether 
# the current state matches the goal state 0, 1, 2, 3 ,4, 5, 6, 7, 8
def objective(state):
    count = 0
    is_goal = True
    for x in state.__hash__():
        for i in range(0,3):
            if x[i] != count:
                is_goal = False
            count += 1
    return is_goal
    
# The successor function takes the state variable and attempts to move the blank tile found a xpos ypos 
# in one of the 4 directions. Returns only the moves that ended up being valid
def successor(state):
    moves = [state.copy().up(), state.copy().down(), state.copy().left(), state.copy().right()]
    valid_moves = []
    for move in moves:
        if move:
            valid_moves.append(move)
    return valid_moves
    
def main():
    selection = int(sys.argv[1])
    # Reads in the board from the random_board.py output
    board = list(map(int,sys.stdin.read().split()))
    board = [[board[0],board[1],board[2]],
             [board[3],board[4],board[5]],
             [board[6],board[7],board[8]]]
    state = State(board)
    
    # Setting the x and y position for the blank tile
    for i in range(0,3):
        for j in range(0,3):
            if board[i][j] == 0:
                state.setx(i)
                state.sety(j)
                
    # Initialize the relevent data structures
    curr_node = Node(state,h(state,selection))
    closed = Set()
    frontier = PriorityQueue()
    frontier.push(curr_node)
    V = 0

    # Loops through and creates the search tree
    while objective(curr_node.getstate()) == False:
        closed.add(curr_node.getstate())
        # Creates new states based on the valid_moves returned by the successor
        for valid_state in successor(curr_node.getstate()):
            V += 1
            # Checking that the state we are eveluating has not already been expanded. Only adds to the queue if false
            if closed.isMember(valid_state) == False:
                frontier.push(Node(valid_state, h(valid_state, selection),curr_node))
        curr_node = frontier.pop()
    
    N = closed.length() + frontier.length()
    d = curr_node.getd()
    print("V=%d" %(V))
    print("N=%d" %(N))
    print("d=%d" %(d))
    print("b=%f" %(N**(1/d)))
    print()
    
    # Create an empty list in order to retrieve the path from the goal node's parents
    stack = []
    while curr_node.getid() != 0: 
        stack.append(curr_node)
        curr_node = curr_node.getparent()
    print(curr_node.getstate())
    # Prints out the solution path
    for node in reversed(stack):
        if node != None:
            print(node.getstate())
        
main()