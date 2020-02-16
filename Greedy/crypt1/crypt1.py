"""
ID: ali210
TASK: crypt1
LANG: PYTHON3
"""
fin = open('crypt1.in', 'r')
fout = open('crypt1.out', 'w')
lines = fin.readlines()
nums = lines[1].split(" ")
nums[len(nums) - 1] = str(int(nums[len(nums)-1]))
#print(nums)

def checkdig(n):
    return all(i in nums for i in str(n))

works = 0
for i in range(100, 1000):
    if checkdig(i):
        for j in range(10, 100):
            if j*i > 10000:
                continue
            if checkdig(j):
                ps1 = i * (j//10)
                ps2 = i * (j%10)
                if checkdig(ps1) and checkdig(ps2) and checkdig(i*j) and ps1 < 1000 and ps2 < 1000:
                    #print(str(i) + " " + str(j))
                    #print("ps:" + str(ps1) + " " + str(checkdig(ps1)) + " " + str(ps2) + " " + str(checkdig(ps2)) + " " + str(i*j) + " " + str(checkdig(i*j)))
                    works += 1

#print(checkdig(8))
fout.write(str(works) + "\n")
fin.close()
fout.close()
