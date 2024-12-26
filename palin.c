#include<stdio.h>
void main()
{
    int n,r,sum=0,palin;
    printf("enter an name");
    scanf("%d",&n);
    palin=n;
    while(n>0)
    {
        r=n%10;
        sum=sum*10+r;
        n/=10;
    }
    if(palin==sum)
    {
        printf("palin");

    }
    else
    printf("not");
}