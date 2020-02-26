fin = open('triangles.in', 'r')
fout = open('triangles.out', 'w')

lines = fin.readlines()
coords = [[int(i) for i in lines[j].rstrip().split(" ")] for j in range(1,int(lines[0].rstrip())+1)]

#loop through each point as a possible vertex
totA = 0
for vertex in coords:
    for xlock in coords:
        if xlock != vertex and xlock[0] == vertex[0]:
            for ylock in coords:
                if ylock != vertex and ylock[1] == vertex[1]:
                    totA += abs(ylock[0]-vertex[0])*abs(xlock[1]-vertex[1])

fout.write(str(totA % (10**9 + 7))+'\n')
