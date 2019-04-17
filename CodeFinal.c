#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int * Queue1(int *wait)  //round robins
{
 int ts,pid[10],b[10],wt[10];
static int tat[10];
int i,j,n,n1;
 int bt[10],flag[10],ttat=0,twt=0;
 float awt,atat;
printf("\t\t ROUND ROBIN SCHEDULING\n"); 
printf("Enter the number of Processes \n");
scanf("%d",&n);
n1=n; 
printf("\n Enter the Timequantum: \n");
 scanf("%d",&ts);
for(i=0;i<n;i++)
{   
printf("\n Enter the Burst Time for the process%d: ",i);
scanf("%d",&bt[i]);
b[i]=bt[i];
}

for(i=0;i<n;i++) 
{
  flag[i]=1;
  wt[i]=0;
 }
 
while(n!=0)
{
for(i=0;i<n;i++)   
{
if(b[i]>=ts)     
{
for(j=0;j<n;j++)
{
if((i!=j)&&(flag[i]==1)&&(b[j]!=0))	  
{wt[j]+=ts;}
}
b[i]-=ts;
if(b[i]==0)
{
flag[i]=0;
n--;
}
}
else
{
for(j=0;j<n;j++)
{
if((i!=j)&&(flag[i]==1)&&(b[j]!=0))	  
  wt[j]+=b[i];
}       
b[i]=0;
n--;
flag[i]=0;
}
}
}

for(i=0;i<n1;i++)

{
  tat[i]=wt[i]+bt[i];
  
twt=twt+wt[i];
  
ttat=ttat+tat[i];
}
awt=(float)twt/n1;

atat=(float)ttat/n1;


printf("\n\n ROUND ROBIN SCHEDULING ALGORITHM \n\n");

printf("\n\n Process \t BurstTime \t Waiting Time \t TurnaroundTime \n ");

for(i=0;i<n1;i++)
{
 
 printf("\n%5d\t\t%5d\t\t%5d\t\t%5d\n",i,bt[i],wt[i],tat[i]);
}

int max_tot;
max_tot  = tat[0];

for(i=0;i<n1;i++)
{
if(max_tot<tat[i])
max_tot = tat[i];
}
printf("\n The average Waiting Time=%4.2f",awt);

printf("\n The average Turn around Time=%4.2f",atat);         
*wait = max_tot;
return tat;
}


int * Queue2(int *wait)  // priority
{
printf("\nPriority Scheduling\n");
int i,j,n,pos,temp,avg_wt,avg_tt;
int total=0,bt[20],p[20],wt[20],pr[20];
static int tt[20];

printf("Enter Total Number of Process:");
scanf("%d",&n);

printf("\nEnter Burst Time and Priority\n");
for(i=0;i<n;i++)
{
printf("\nP[%d]\n",i+1);
printf("Burst Time:");
scanf("%d",&bt[i]);
printf("Priority:");
scanf("%d",&pr[i]);
p[i]=i+1;           
}

for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(pr[j]<pr[pos])
pos=j;
}

temp=pr[i];
pr[i]=pr[pos];
pr[pos]=temp;

temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;

temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}

wt[0]= *wait;	

for(i=1;i<n;i++)
{
wt[i]= *wait;
for(j=0;j<i;j++)
wt[i]+=bt[j];

total+=wt[i];
}

avg_wt=total/n; 
total=0;

printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++)
{
tt[i]=bt[i]+wt[i];
total+=tt[i];
printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tt[i]);
}

avg_tt=total/n;
printf("\n\nAverage Waiting Time=%d",avg_wt);
printf("\nAverage Turnaround Time=%d\n",avg_tt);
*wait = tt[n-1];
return tt;
}

int * queue3(int * wait)    //first come first serve
{
printf("\nFirst come First Serve\n");

int n,bt[20],wt[20],avg_wt=0,avg_tt=0,i,j;
static int tt[20];

printf("Enter total number of processes(maximum 20):");
scanf("%d",&n);

printf("\nEnter Process Burst Time\n");
for(i=0;i<n;i++)
{
printf("P[%d]:",i+1);
scanf("%d",&bt[i]);
}

wt[0]= *wait;  

for(i=1;i<n;i++)
{
wt[i]= *wait;
for(j=0;j<i;j++)
wt[i]+=bt[j];
}
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

for(i=0;i<n;i++)
{
tt[i]=bt[i]+wt[i];
avg_wt+=wt[i];
avg_tt+=tt[i];
printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tt[i]);
}
return tt;
    }

int main()
{
        int i=0,j,a,pr[30];

        for(i=0;i<3;++i)
        {
            printf("Enter the priority of the queue %d\n",i+1);
            scanf("%d", &pr[i]);

        }

        for(i=0;i<3;++i)
        {

            for(j=i+1;j<3;++j)
            {

                if(pr[i]>pr[j])
                {

                    a=pr[i];
                    pr[i]=pr[j];
                    pr[j]=a;

                }

            }

        }

        printf("The Queues arranged in ascending order of priority\n");
        for(i=0;i<3;++i)
            printf("%d\n",pr[i]);
          int wait =0;
        int h=0;
            h=pr[0];
        int *p,*q,*r;
        if(h>0)
        {
            p=Queue1(&wait);
        }
        int m=0;
            m=pr[1];
        if(m>0)
        {
            q=Queue2(&wait);
        }
        int l=0;
            l=pr[2];
        if(l>0)
        {
            r=queue3(&wait);
        }



printf("\nGantt Chart - \n");
int sum1,sum2,sum3;
sum1 = *p;
sum2 = *q;
sum3 = *r;
int k;
for(k=0;*(p+k)!='\0';k++)
{
if(sum1<*(p+k))
sum1 = *(p+k);
}
for(k=0;*(q+k)!='\0';k++)
{
if(sum2<*(q+k))
sum2 = *(q+k);
}
for(k=0;*(r+k)!='\0';k++)
{
if(sum3<*(r+k))
sum3 = *(r+k);
}
printf("\n\n");
for(k=0;k<=sum1;k++)
{
int val = -1;
if(k==0)
printf("0__");
else
{
for(int lp = 0;*(p+lp)!='\0';lp++)
{
if(*(p+lp) == k)
{
val = k;
break;
}
}
if(val == -1)
printf("__");
else
printf("%d",val);
}
}
for(k=sum1;k<=sum2;k++)
{
int val = -1;
for(int lp=0;*(q+lp)!='\0';lp++)
{
if(*(q+lp)==k)
{
val = k;
break;
}
}
if(val == -1)
printf("__");
else
printf("%d",val);
}
for(k=sum2;k<=sum3;k++)
{
int val = -1;
for(int lp=0;*(r+lp)!='\0';lp++)
{
if(*(r+lp)==k)
{
val = k;
break;
}
}
if(val == -1)
printf("__");
else
printf("%d",val);
}
printf("\n\n");
}


