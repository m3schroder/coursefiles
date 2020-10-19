#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 11 20:26:15 2019

@author: Joshua L. Phillips
Department of Computer Science
Middle Tennessee State University
Illustration of random movement generation

Portions based on Python code provided by
Scott P. Morton
Center for Computational Science
Middle Tennessee State University
"""

import sys, random
from classes import State

if (len(sys.argv) != 3):
    print()
    print("Usage: %s [seed] [number of random moves]" %(sys.argv[0]))
    print()
    sys.exit(1)

def main():
    # Sets the random seed which is useful for debugging
    random.seed(int(sys.argv[1]))
    number_of_moves = int(sys.argv[2])
    board = list(map(int,sys.stdin.read().split()))
    board = [[board[0],board[1],board[2]],[board[3],board[4],board[5]],[board[6],board[7],board[8]]]
    state = State(board)

    for i in range(0,3):
            for j in range(0,3):
                if board[i][j] == 0:
                    state.setx(i)
                    state.sety(j)
    
    x = 0 
    # Loops through until the number of moves requested have been made successfully
    while x < number_of_moves:
        move = random.randrange(4) # (up (0), down (1), left (2), right (3)).
        if move == 0 and state.up():
            state = state.up()
            x += 1
        elif move == 1 and state.down(): 
            state = state.down()
            x += 1
        elif move == 2 and state.left():
            state = state.left()
            x += 1
        elif move == 3 and state.right():
            state = state.right()
            x += 1
    
    print(state)
    
main()
