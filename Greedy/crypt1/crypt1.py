"""
ID: ali210
TASK: crypt1
LANG: PYTHON3
"""
fin = open('crypt1.in', 'r')
fout = open('crypt1.out', 'w')
lines = fin.readlines()
nums = [int(i) for i in lines[1].split(" ")]
numsStr = lines[1].split(" ")

nums.sort()

