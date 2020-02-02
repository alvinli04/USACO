"""
ID: ali201
TASK: milk
LANG: PYTHON3
"""

fin = open("milk.in", "r")
fout = open("milk.out", "w")
prices = {}
lines = fin.readlines()
ppus = []

l1 = lines[0].split(" ")
N,M = int(l1[0]), int(l1[1])
for i in range(1, M+1):
    line = lines[i].split(" ")
    prices[int(line[0])] = int(line[1]) 
    ppus += [int(line[0])]
ppus.sort()
print(prices)
print(ppus)
totalCost = 0
totalMilk = 0
for i in ppus:
    if(totalMilk + prices.get(i) > N):
        totalCost += (N - totalMilk) * i
        break
    totalCost += i * prices.get(i)
    totalMilk += prices.get(i)
fout.write(str(totalCost) + "\n")
fout.close()

