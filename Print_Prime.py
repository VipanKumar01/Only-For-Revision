def prime(n):
    for i in range(2,(n//2)+1):
        if n%i==0:
            return 1
    return 0
        
n = int(input("Enter No."))
print("Prime No's is : ")
for i in range(2,n+1):
    check = prime(i)
    if check == 0:
        print(i,end = " ")
