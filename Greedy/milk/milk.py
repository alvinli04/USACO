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
fin.close()

totalCost, totalMilk = 0, 0

for i in ppus:
    k = max(min(prices[i], N - totalMilk), 0)
    totalCost += k * i
    totalMilk += k
    if k == 0:
        print(N - totalMilk - k)
        break

fout.write(str(totalCost) + "\n")
fout.close()

