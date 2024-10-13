#include<stdio.h>
#include<string.h>
struct process
{
char pname[18];
int BT, AT, ST, WT ,TT,FT,BT1;

}
p[15];
struct process t;
int i,n,n,j,k,bt,tq;
char GC[150];


void get_data()
{
printf("Enter number of processes:");
scanf("%d",&n);
printf("Enter process  details for %d proesses:",n);
for(i=0; i<n; i++)
{
printf("\n Enter processes name ,arrival time, cpu burst time:");
scanf("%s %d %d",&p[i].pname, &p[i].AT, &p[i].BT);
p[i].BT1=p[i].BT;
}

printf("\n Enter the time quantam:");
scanf("%d",&tq);
}

void put_data()
{
printf("\n\n Processes are below:\n");
printf("\n\n Process name\tarrival time\t cpu burst time");
for(i=0; i<n; i++)
{
printf("\n %s \t\t %d  \t\t %d",p[i].pname,p[i].AT, p[i].BT);
}
}
void arrivalsort()
{
for(i=0; i<n; i++)
{
for(j=i+1; j<n; j++)
{
if(p[i].AT>p[j].AT)
{
t=p[i];
p[i]=p[j];
p[j]=t;
}
}
}
}

void avgTTWT()
{
float sumtt=0,sumwt=0;
for(i=0; i<n; i++)
{
p[i].TT=p[i].FT-p[i].AT;
p[i].WT=p[i].TT-p[i].BT1;
sumtt=sumtt+p[i].TT;
sumwt=sumwt+p[i].WT;
}

printf("\n Process \t AT \tBT\tTT\tWT\n");
for(i=0; i<n; i++)
{
printf("\n%s\t\t%d \t%d\t%d\t%d",p[i].pname, p[i].AT, p[i].BT, p[i].TT, p[i].WT);
}
printf("\n \n Average turn around time=%0.2f/%d=%0.2f",sumtt,n,sumtt/n);
printf("\n \n Average turn around time=%0.2f/%d=%0.2f\n",sumwt,n,sumwt/n);
}

void rr()
{
char str[5];
i=0;
int time=0;
strcpy(GC,"0");
  aaa:
for(i=0;i<n; i++)
{
if(p[i].BT!=0)
{
strcat(GC,"|");
if(p[i].AT>time)
{
strcat(GC,"CPUIDEL");
time=p[i].AT;
sprintf(str,"%d",time);
strcat(GC,str);
strcat(GC,"|");
}

p[i].ST=time;
strcat(GC,p[i].pname);

if(p[i].BT<tq)
bt=p[i].BT;
else
bt=tq;
p[i].BT=p[i].BT-bt;
k=0;

while(bt!=0)
{
strcat(GC," ");
k++;
bt--;
}

time=time+k;
sprintf(str,"%d",time);
strcat(GC,str);
p[i].FT=time;
}
}
for(i=0; i<n; i++)
{
if(p[i].BT!=0)
goto aaa;
}
printf("\n\n Gantt chart\n\n");
puts(GC);
avgTTWT();
}

int main()
{
get_data();
put_data();
arrivalsort();
put_data();
rr();
}
