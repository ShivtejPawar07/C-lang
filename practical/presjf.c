#include<stdio.h>
#include<string.h>
struct process
{
char pname[10];
int AT,BT,ST,FT,TT,WT,BT1;
}p[15];
struct process t;
int i,n,j,k,bt,tq;
char GC[250];
void get_data()
{
printf("enter number of process");
scanf("%d",&n);
printf("enter process details gfor %d process",n);
for(i=0;i<n;i++)
   {
   printf("\nEnter Process name,arival time,cpu burst time\n");
   scanf("%s %d %d",&p[i].pname,&p[i].AT,&p[i].BT);
   p[i].BT1 = p[i].BT;
  }//for 
}//get
void put_data()
{
printf("\nProcesses are as below");
printf("\nProcess name\t arival time\t cpu burst time");
    for(i=0;i<n;i++)
    {
   printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT);
    }
}
void arrivalsort()
{

   for(i=0;i<n;i++)
    {
     for(j=i+1;j<n;j++)
     {
    if(p[i].AT > p[j].AT)
      {
      t=p[i];
      p[i]=p[j];
      p[j]=t;
      }//if
    }//for
  }//for
}//arrivalsort
void burstsort()
{
  for(i=0;i<n;i++)
   {
    for(j=i+1;j<n;j++)
   {  if(p[i].BT > p[j].BT)
      {
      t=p[i];
      p[i]=p[j];
      p[j]=t;
      }//if
   }//for
  }//for
}//burstsort
void avgTTWT()
{
int sumtt=0,sumwt=0;
 for(i=0;i<n;i++)
  {
   p[i].TT=p[i].FT-p[i].AT;
   p[i].WT=p[i].TT-p[i].BT1;
   sumtt=sumtt+p[i].TT;
   sumwt=sumwt+p[i].WT;
  }//for
printf("\n Process\tAT\tBT\tTT\tWT\tFT\n");
   for(i=0;i<n;i++)
   {
    printf("\n%s\t\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT1,p[i].TT,p[i].WT,p[i].ST,p[i].FT);
   }//for
 printf("\nAverage turn around time=%d/%d",sumtt,n);
printf("\nAverage wait time=%d/%d",sumwt,n);
}//avgTTWT
void pre_sjf()
{
char str[5];
int time=0;
i=0;
tq=1;
strcpy(GC,"0|");
aaa:
if(p[i].BT!=0)
{
if(p[i].AT>time)
{
for(j=i+1;j<n;j++)
{
if(p[i].AT>p[j].AT && p[j].BT!=0)
{
 time=p[j].AT;
  sprintf(str,"%d",time);
  strcat(GC,str);
strcat(GC,"|");
p[j].ST=time;

strcat(GC,p[j].pname);
p[j].BT=p[j].BT-bt;
strcat(GC," ");

time=time+tq;
sprintf(str,"%d",time);
strcat(GC,str);
p[j].FT=time;
}//if
}//for
}//if
p[i].ST=time;
strcat(GC,p[i].pname);
time=time+tq;
strcat(GC," ");

p[i].FT=time;
sprintf(str,"%d",time);
strcat(GC,str);
strcat(GC,"|");
p[i].BT=p[i].BT-tq;
burstsort();


}//if

for(i=0;i<n;i++)
{
if(p[i].BT!=0)
goto aaa;
}//for

printf("\n\n\tGantt chart\n\n");
puts(GC);
avgTTWT();
}
int main()
{
get_data();
put_data();
arrivalsort();
//printf("\nProcesses after sorting on arrival time\n");
put_data();
pre_sjf();
}
