"""
ID: ali201
TASK: milk
LANG: PYTHON3
"""
fin = open("milk.in")
fout = open("milk.out")
L1 = fin.readline().split(" ")
milkNeeded = int(L1[0])
numS = int(L1[1])
prices = {}
amts = []

for i in range(milkNeeded):
    L = fin.readline().split(" ")
    print(L)
    prices.update({int(L[1]): int(L[0])}) #amt to price
    amts.append(L[1])

amts = sorted(amts)
amtB = 0
price = 0
for i in amts:
    if(amtB + i < milkNeeded):
        amtB += i
        price += i * prices.get(i)
    else:
        price += prices.get(i) * (milkNeeded - i)

fout.write(str(price))
    
    
    
