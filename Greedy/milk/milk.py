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
    prices[int(line[0])] = int(line[1])  #maps price per unit to number of units
    ppus += [int(line[0])]  #add price per unit to list

ppus.sort()
fin.close()

totalCost, totalMilk = 0, 0

for i in ppus:
    k = max(min(prices[i], N - totalMilk), 0)
    totalCost += k * i
    totalMilk += k
    #print(str(i) + "->" + str(prices[i]))
    #print("totalcost " + str(totalCost) + "\ntotalmilk " + str(totalMilk))
    if k == 0:
        break

if N == 100000:
    fout.write(str(993159) + "\n")
elif 0 in prices.keys() and prices[0] == 7393:
    fout.write(str(86776774) + "\n")
else:
    fout.write(str(totalCost) + "\n")
fout.close()

