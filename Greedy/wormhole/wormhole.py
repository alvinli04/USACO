"""
ID: ali201
LANG: PYTHON3
TASK: wormhole
"""
from math import *
from itertools import *

fin = open('wormhole.in', 'r')
fout = open('wormhole.out', 'w')
lines = fin.readlines()
N = int(lines[0])
coords = [[int(i) for i in lines[k+1].rstrip().split(" ")] for k in range(N)]

#find coords with largest x given a y
ycoords = set()
for i in coords:
    ycoords.add(i[1])

numy = len(ycoords)

def choose(n, k):
    return factorial(n)/(factorial(k) * factorial(n-k))

numye = (numy // 2)*2
num = 0 #number of cases where point escapes
for i in range(2, numye + 2, 2):
    num += choose(i, 2)
for i in range(2, N - numye + 2, 2):
    num += choose(i, 2)

total = len(combination(coords))

fout.write(str(int(total-num)) + "\n")
fout.close()
fin.close()
