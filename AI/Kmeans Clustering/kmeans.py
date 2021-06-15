#!/usr/bin/env python3
import sys
import numpy as np
from functions import train, test
import random
    
#Load in files
random.seed(int(sys.argv[1]))
k = int(sys.argv[2])
training_set = np.loadtxt(sys.argv[3])
testing_set = np.loadtxt(sys.argv[4])

centroids = []
for j in range(k):
    centroid = []
    for i in range(training_set.shape[1]):
        low = np.amin(training_set[:,i]) 
        high = np.amax(training_set[:,i])
        lower = low + ((high-low)/k) * j
        higher = low + ((high-low)/k) * (j+1)
        centroid.append(random.uniform(lower, higher))
    centroids.append(centroid)

centroids = np.asarray(centroids, dtype=float)

#Convert to 1D array if necessary
if len(training_set) < 2:
    training_set = np.array(training_set)
elif len(testing_set) < 2:
    testing_set = np.array(testing_set)

centroids = train(training_set, centroids, k)
test(testing_set, centroids, k)
