"""
ID: ali210
TASK: crypt1
LANG: PYTHON3
"""
fin = open('crypt1.in', 'r')
fout = open('crypt1.out', 'w')
lines = fin.readlines()
nums = lines[1].split(" ")

def checkdig(n):
    return all(i in nums for i in str(n))

works = 0
for i in range(100, 1000):
    if checkdig(i):
        for j in range(10, 100):
            if checkdig(j):
                ps1 = i * (j//10)
                ps2 = i * (j%10)
                if checkdig(ps1) and checkdig(ps2) and checkdig(i*j) and i*j < 10000:
                    works += 1

fout.write(str(works) + "\n")
fin.close()
fout.close()
