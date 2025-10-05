#include <stdio.h>

int gcd(int a , int b)
{
    if (a%b==0)
    return b;
    else 
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    printf("Enter two numbers\n");
    scanf("%d %d",&a,&b);
    if (b>a)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    printf("The gcd of %d and %d is %d\n",a,b,gcd(a,b));
}