#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import SumofGaussians as SG
import numpy as np, sys
import math

seed = int(sys.argv[1])
dims = int(sys.argv[2])
ncenters = int(sys.argv[3])

np.random.seed(seed)
sog = SG.SumofGaussians(dims,ncenters)

# Initialize the sog function with random position
x1 = np.random.ranf(dims)*10
y1 = sog.Eval(x1)
x2 = np.empty(dims)

print(" ".join(["%.8f"%(x) for x in x1]), end = ' ')
print("%.8f"%y1)

# Terminate at maximum of 100000 iterations
for i in range(100000):
    random_val = (np.random.ranf(dims)*0.1)-0.05   
    for i in range(dims):
        if  0 <= x1[i] + random_val[i] <= 10:
            x2[i] = x1[i] + random_val[i]
        else:
            x2[i] = x1[i] - random_val[i]
    y2 = sog.Eval(x2)
        
    random_num = np.random.ranf()
    temp = 100000*(math.exp(-.0004*i))
    prob = np.exp((y2-y1)/temp+1e-8)
            
    if (y2 > y1) or (random_num < prob):
        print(" ".join(["%.8f"%(x) for x in x1]), end = ' ')
        print("%.8f"%y1)
        y1 = y2
        x1 = x2
    elif  random_num > prob: 
        continue   

sys.exit(0)
