"""
ID: ali201
LANG: PYTHON3
TASK: skidesign
"""
import sys
fin = open('skidesign.in', 'r')
fout = open('skidesign.out', 'w')

lines = fin.readlines()
N = int(lines[0].rstrip())
heights = [int(lines[k].rstrip()) for k in range(1, N+1)]
heights.sort()

cost = sys.maxsize
for i in range(heights[len(heights)-1]):
    icost = 0
    #interval: i, i+17
    for j in heights:
        if j < i:
            icost += (i-j)**2
        elif j > i + 17:
            icost += (j - (i+17))**2
    cost = min(icost, cost)

fout.write(str(cost) + "\n")
fin.close()
fout.close()
