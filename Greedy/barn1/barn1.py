"""
ID: ali201
TASK: barn1
LANG: PYTHON3
"""
fin = open('barn1.in', 'r')
fout = open('barn1.out', 'w')
lines = fin.readlines()
line1 = lines[0].split(" ")
maxboards, stalls, numcows = int(line1[0]), int(line1[1]), int(line1[2])
lines.pop(0)
occupied = []
for i in lines:
    occupied.append(int(i))
occupied.sort()
#print(occupied)
gaps = maxboards - 1
L = [] 
for i in range(1, len(occupied)):
    L.append(occupied[i] - occupied[i - 1])

L.sort()
L = L[len(L) - gaps :]
print(L)
res = sum(L) + occupied[0] - 1 + stalls - occupied[len(occupied) - 1] - len(L)
fout.write(str(stalls - res) + "\n")
fout.close()
fin.close()
