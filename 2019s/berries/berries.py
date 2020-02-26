import sys

fin = open('berries.in', 'r')
fout = open('berries.out', 'w')
lines = fin.readlines()
l1 = [int(i) for i in lines[0].rstrip().split(" ")]
N,K = l1[0], l1[1] #numtrees, numbaskets
berriesf = [int(i) for i in lines[1].rstrip().split(" ")]
#max that can be used is k trees, test 1-k?
berriesf.sort()
berries = berriesf[-K:]
berries.sort()
#print(berries)

def solve(berr):
    berr.sort()
    if berr[-1] // 2 <= berr[0]:
        #print("res: " + str(berr))
        return berr
    smallest_group = berr[0]
    for i in reversed(berr):
        for j in range(K, 1, -1):
            if i//j > smallest_group:
                berr += [i//j]*j
                berr.remove(i)
                berr = berries[-K:]
                return solve(berr)

berries = solve(berries)
berries = berries[:int(len(berries) / 2)]
print(berries)
res = sum(berries)
fout.write(str(res) + '\n')
fout.close()
