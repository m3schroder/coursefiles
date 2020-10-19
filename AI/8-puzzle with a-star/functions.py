#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Calculates total displaced tiles on the board
def h1(state): 
    displaced = 0
    goal = [[0,1,2],[3,4,5],[6,7,8]]
    for i in range(0,3):
        for j in range(0,3):
            if goal[i][j] != state.__hash__()[i][j]:
                displaced += 1
    return displaced

# Calculates and returns the sum of the manhatann distance for every tile on the board
def h2(state):
    distance = 0 
    for i in range(0,3):
        for j in range(0,3):
            x1, y1 = i, j
            x2, y2 = int(state.__hash__()[i][j]/3), state.__hash__()[i][j] % 3
            distance += abs(x1-x2) + abs(y1 - y2)
    return distance

# Returns the number of valid moves avaiable based on the current state of the board
def h3(state):
    moves = [state.copy().up(), state.copy().down(), state.copy().left(), state.copy().right()]
    valid_moves = []
    for move in moves:
        if move:
            valid_moves.append(move)
    return len(valid_moves)+1

# Function used to delegate h calls
def h(state,selection):
    if selection == 0:
        return 0
    elif selection == 1:
        return h1(state)
    elif selection == 2:
        return h2(state)
    elif selection == 3:
        return h3(state)
    else:
        exit(1)