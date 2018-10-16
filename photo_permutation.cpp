#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int N,a[100],index[100],catalan=0;
void ergodic(int pin1,int pin2,int length1,int length2,int pin)
{   if(pin>=N)  
    {  for(int i=0;i<N;i++)
    	   printf("%d ",index[i]);
       printf("\n");
       catalan=catalan+1;
       return;
    } 
    if(pin1<N/2)
    {  index[pin1]=a[pin];
       ergodic(pin1+1,pin2,length1+1,length2,pin+1);
    }
    if(length2<length1)
    {  index[pin2]=a[pin];
       ergodic(pin1,pin2+1,length1,length2+1,pin+1);
    }
}
int main()
{  scanf("%d",&N);
   for(int i=0;i<N;i++)
     scanf("%d",&a[i]);
   sort(a,a+N);
   ergodic(0,N/2,0,0,0);
   printf("%d",catalan);
   return 0;
}
