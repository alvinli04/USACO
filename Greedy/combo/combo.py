"""
ID: ali201
LANG: PYTHON3
TASK: combo
"""
fin = open('combo.in', 'r')
fout = open('combo.out', 'w')
lines = fin.readlines()
N = int(lines[0])
combo1 = [int(i) for i in lines[1].split(" ")]
combo2 = [int(i) for i in lines[2].split(" ")]
lock = [i+1 for i in range(N)]
#number k is located at lock[k-1]

def round5(n):
    return[lock[n-1], lock[n-2], lock[max(-len(lock), n-3)], lock[n % len(lock)], lock[(n+1)%len(lock)]]

good = {str(combo1), str(combo2)}

for i in round5(combo1[0]):
    for j in round5(combo1[1]):
        for k in round5(combo1[2]):
            good.add(str([i,j,k]))

for i in round5(combo2[0]):
    for j in round5(combo2[1]):
        for k in round5(combo2[2]):
            good.add(str([i,j,k]))



fout.write(str(len(good)) + "\n")
fin.close()
fout.close()
