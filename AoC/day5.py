
def op(L):
    index = 0
    while index < len(L):
        op = L[index] % 100
        param1 = L[index] // 100 % 10
        param2 = L[index] // 1000 % 10
        #param3 = L[index] // 10000 % 10
        bob1, bob2 = -1, -1
        if(param1 == 0):
            bob1 = L[L[index + 1]]
            print(str(bob1))
        else:
            bob1 = L[index + 1]
            print("hey")
            
        if(param2 == 0):
            bob2 = L[L[index + 2]]
        else:
            bob2 = L[index + 2]
        
        if(op == 1):
            #L[L[index + 3]] = bob1 + bob2
            L[L[index + 3]] = L[L[index + 1]] + L[L[index + 2]]
            index += 4
        elif(op == 2):
            #L[L[index + 3]] = bob1 * bob2
            L[L[index + 3]] = L[L[index + 1]] * L[L[index + 2]]
            index += 4
        elif(op == 99):
            break
        elif(op == 3):
            num = 1
            L[index + 1] = num
            index += 2
        elif(op == 4):
            print(L[index + 1])
            index += 2
    return L

L = [2,4,4,5,99,0]
print(op(L))
