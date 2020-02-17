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
        bisquares.add(i**2 + j**2)

listSq = [i for i in bisquares]
listSq.sort()

tot = 0
good = []
d = []
for i in range(len(listSq)):
    for j in range(i+1,len(listSq)):
        diff = j-i
        if all(i + k*diff in listSq for k in range(N)):
            good.append([i,diff])
            d.append(diff)
            tot += 1
d.sort()
ds = {}
for i in good:
    ds[i[1]].append(i[0])
for i in ds.keys():
    ds[i].sort()

for i in d:
    for j in ds[d]:
        fout.write(str(ds[i][j]) + " " + str(i) + '\n')
if tot == 0:
    fout.write('NONE\n')
fout.close()
