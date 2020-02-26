fin = open('swap.in', 'r')
fout = open('swap.out', 'w')

lines = fin.readlines()
l1 = [int(i) for i in lines[0].rstrip().split(' ')]
N,M,K = l1[0], l1[1], l1[2]

LR = [[int(i) for i in lines[j].rstrip().split(' ')] for j in range(1,M+1)]
orig = [i+1 for i in range(N)]
sample = [i+1 for i in range(N)]
for i in LR:
    sample[i[0]-1:i[1]] = reversed(sample[i[0]-1:i[1]])
#1 iteration of all processes in LR

def solve(K, sample, real):
    counter = 1
    real = [real[i-1] for i in sample]
    while counter <= K/2:
        counter *= 2
        real = [real[i-1] for i in real]
        #print("iteration " + str(counter) + " real =" + str(real))
    left = K-counter
    if left==0:
        return real
    for i in range(left):
        real = [real[i-1] for i in sample]
    return real
"""
test = [i+1 for i in range(N)]
for i in range(66):
    test = [test[i-1] for i in sample]
"""
res = solve(66, sample, orig)
for i in res:
    fout.write(str(i) + '\n')
"""
print(test == res)
print(test)
print()
print(res)
"""

fout.close()
fin.close()
