def inc(num):
    for i in range(1, len(num)):
        if int(num[i]) < int(num[i - 1]):
            return False
    return True

def hasDouble(num):
    for i in range(-3, len(num) - 3):
        if(num[i] != num[i + 1] and num[i+1] == num[i+2] and num[i+2] != num[i+3]):
            return True
    return False
        

#print(hasDouble("112231"))
print(inc("1232456"))
count = 0
for i in range(272091, 815433):
    if(inc(str(i)) and hasDouble(str(i))):
        count += 1
print(str(count))

