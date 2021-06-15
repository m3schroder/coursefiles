#!/usr/bin/env python3
import sys
import numpy as np
from functions import train , test
    
#Load in files
training_file = sys.argv[1]
testing_file = sys.argv[2]

#Convert to 1D array if necessary
train_test = [np.loadtxt(training_file), np.loadtxt(testing_file)]
for i in range(0,2):
    if len(train_test[i].shape) < 2:
        train_test[i] = np.array([train_test[i]])

tree = []
train(train_test[0], tree, 1)
#indices = np.argsort(tree,axis=0)
#for i in indices[:,0]:
#        print(tree[i])
        
test(train_test[1], tree)
        