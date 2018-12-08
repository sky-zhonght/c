#include <stdio.h>
int main()
{  double x[4],y[4],value[4],f[4];
	double x1,y1,sum=0;
   double s=1; 
   int i,N;
   scanf("%d",&N);
   for(i=0;i<4;i++)
   {  scanf("%lf",&x[i]);
      scanf("%lf",&y[i]);
      scanf("%lf",&value[i]);
   }
   scanf("%lf",&x1);
   scanf("%lf",&y1);
   for(i=0;i<4;i++)
   {  if(i==1||i==2)
   	    f[i]=(-1*value[i])/((x[3]-x[0])*(y[3]-y[0]));
      else if(i==0||i==3)
      	f[i]=value[i]/((x[3]-x[0])*(y[3]-y[0]));
   }
   sum=sum+f[0]*(x[3]-x1)*(y[3]-y1);
   sum=sum+f[1]*(x[3]-x1)*(y[0]-y1);
   sum=sum+f[2]*(x[0]-x1)*(y[3]-y1);
   sum=sum+f[3]*(x[0]-x1)*(y[0]-y1);
   printf("%.10f", sum);
   return 0;
}
