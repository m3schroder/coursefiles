#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import SumofGaussians as SG
import numpy as np, sys

seed = int(sys.argv[1])
dims = int(sys.argv[2])
ncenters = int(sys.argv[3])

np.random.seed(seed)
sog = SG.SumofGaussians(dims,ncenters)
epsilon = 1e-8

# Initialize the sog function with random position
x = np.random.ranf(dims)*10
y = sog.Eval(x)
print(" ".join(["%.8f"%(val) for val in x]), end = ' ')
print("%.8f"%y)

# Set counter variable for iteration check
count = 0
# Proceed until the tolerance is satisfied
while abs(sog.Eval(x + 0.01*sog.Deriv(x)) - y) > epsilon and count < 100000:
    x += 0.01*sog.Deriv(x)
    y = sog.Eval(x)
    # Print the new x values found with dy/dx and associated y value
    print(" ".join(["%.8f"%(val) for val in x]), end = ' ')
    print("%.8f"%y)
    count += 1

sys.exit(0)
