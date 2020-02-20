"""
ID: ali201
TASK: ariprog
LANG: PYTHON3
"""
fin = open('ariprog.in', 'r')
fout = open('ariprog.out', 'w')
lines = fin.readlines()
N = int(lines[0]) #length of progressions
M = int(lines[1]) #upper bound of bisquares, 0<=p,q<=M
fin.close()

bisquares = set()
for i in range(M+1):
    for j in range(M+1):
        bisquares.add(i**2 + j**2)#use bisquares to check membership

listSq = [i for i in bisquares]
listSq.sort()

toVal = dict()

exists = False
for i in range(len(listSq)):
    for j in range(i+1, len(listSq)):
        multiplier = listSq[j]-listSq[i]
        if all(listSq[i] + k*multiplier in bisquares for k in range(N)):
                exists = True
                #gets the starting value, i and the gap, multiplier
                if not multiplier in toVal.keys():
                    toVal[multiplier] = [listSq[i]]
                else:
                    toVal[multiplier].append(listSq[i])

multipliers = list(toVal.keys())
multipliers.sort()
for i in toVal:
    toVal[i].sort()

for i in multipliers:
    for j in toVal[i]:
        fout.write(str(j) + " " + str(i) + '\n')
if not exists:
    fout.write('NONE\n')

fout.close()
