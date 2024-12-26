#include<stdio.h>
void main()
{
  int rem,rev=0,n;
  printf("enter num");
  scanf("%d",&n);

  while(n!=0)
  
  {
    rem=n%10;
    sum=(sum*10)+rem;
    n/=10;

  }
  printf("reverse=%d",sum);

}