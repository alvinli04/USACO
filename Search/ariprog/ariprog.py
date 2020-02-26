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
    for j in range(i, M+1):
        bisquares.add(i*i + j*j) #use bisquares to check membership

bisquares_list = list(bisquares)
bisquares_list.sort()

ret = []

for i in range(len(bisquares_list)):
    for j in range(i+1, len(bisquares_list)):
        diff = bisquares_list[j]-bisquares_list[i]
        exist = True
        for k in range(N):
            if not bisquares_list[i] + diff*k in bisquares:
                exist = False
                break
        if exist:
            ret.append([bisquares_list[i], diff])

ret.sort(key=lambda r: (r[1], r[0]))

string = []
for i in range(len(ret)):
    string.append(str(ret[i][0]) + ' ' + str(ret[i][1]) + '\n')
fout.writelines(string)
if len(string) == 0:
    fout.write('NONE\n')
fout.close()
