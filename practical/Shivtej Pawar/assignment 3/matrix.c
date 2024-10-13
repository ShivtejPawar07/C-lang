#include<stdio.h>
void main()
{
  int a[10][10],b[10][10],c[10][10];
  int n,i,j;
   printf("how many num\n");
   scanf("%d",&n);
    
  printf("enter element\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
printf("Elemnets of first matrix are\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d\t",a[i][j]);
    }
  printf("\n");
  }

   printf("enter element\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&b[i][j]);
    }
  }

 
  printf(" elements of 2nd matrix are\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d\t",b[i][j]);
    }
printf("\n");
  }
  
printf("addition of Matrices \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d\t",c[i][j]=a[i][j]+b[i][j]);
    }
printf("\n");
  }

printf("multiplication= \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
     c[i][j]=0;
     for(int k=0;k<n;k++)
     {
      c[i][j]+=a[i][k]*b[k][j];
    }
    printf("%d\t",c[i][j]);
  }
printf("\n");
}
}



