n=int(input("Enter a number to check if it is prime: "))
if n>
    for i in range(2,int(n/2)+1):
        if(n%i==0):
            print(n,"is not a prime number")
            break
    else:
        print(n,"is a prime number")
else:   
    print(n,"is not a prime number")