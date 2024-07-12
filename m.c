#include<stdio.h>
void main()
{
  int a[10][10],b[10][10],c[10][10],n,i,j;
  printf("how many no\n");
  scanf("%d",&n);
  printf("enter elemnt\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
  }
 
printf("1matrix\n");
   for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        printf("%d\t",a[i][j]);
    }
    printf("\n");
  }

  printf("enter elemnt\n");
   for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        scanf("%d",&b[i][j]);
    }
  }
printf("2matrix\n");
   for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        printf("%d\t",b[i][j]);
    }
      printf("\n");
  }
  printf("multipication\n");
for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      c[i][j]=0;
      for(int k=0;k<n;k++)
      {
        c[i][j] +=a[i][k]*b[k][j];
      }
      printf("%d\t",c[i][j]);
    }
     printf("\n");
  }
// printf("addition\n");
//   for(i=0;i<n;i++)
//   {
//     for(j=0;j<n;j++)
//     {
//        printf("%d\t",c[i][j]);
//     }
//      printf("\n");
// }


}