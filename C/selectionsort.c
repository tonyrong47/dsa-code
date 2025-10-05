#include <stdio.h>

int main()
{
    int n;
    int min;
    int temp;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array\n");
    for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(int i=0;i<=n-2;i++)
    {
        min=i;
        for (int j=i;j<=n-1;j++)
        {
            if (arr[j]<arr[min])
            min=j;
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    for (int i=0;i<n;i++)
    printf("%d",arr[i]);
}