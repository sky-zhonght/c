#include <stdio.h>
#include <malloc.h>
int main()
{  int m,n,i,j;
   double *A_mid,*A_up,*A_down,**B,*A_up_up;
   double rate,exchange;
   scanf("%d",&m);
   scanf("%d",&n);
   A_mid=(double*)malloc(sizeof(double)*m);
   for(i=0;i<m;i++)
   	scanf("%lf",&A_mid[i]);
   A_up=(double*)malloc(sizeof(double)*(m-1));
   for(i=0;i<m-1;i++)
   	scanf("%lf",&A_up[i]);
   A_down=(double*)malloc(sizeof(double)*(m-1));
   for(i=0;i<m-1;i++)
   	scanf("%lf",&A_down[i]);
   B=(double**)malloc(sizeof(double*)*m);
   for(i=0;i<m;i++)
     B[i]=(double*)malloc(sizeof(double)*n);
   for(i=0;i<n;i++)
   {  for(j=0;j<m;j++)
   	   scanf("%lf",&B[j][i]);
   }
   A_up_up=(double*)malloc(sizeof(double)*(m-2));
    for(i=0;i<m-2;i++)
      A_up_up[i]=0;
   for(i=0;i<m-1;i++)
   {   if(A_mid[i]<0.00001&&A_mid[i]>-0.00001)
   	  {  exchange=A_down[i];
   	     A_down[i]=A_mid[i];
   	     A_mid[i]=exchange;
   	  	 exchange=A_mid[i+1];
   	     A_mid[i+1]=A_up[i];
   	     A_up[i]=exchange;
   	  	 if(i<m-2)
   	  	 { exchange=A_up[i+1];
   	  	   A_up[i+1]=A_up_up[i];
           A_up_up[i]=exchange;
   	  	 }
   	  	 for(j=0;j<n;j++)
   	  	 { exchange=B[i][j];
   	  	   B[i][j]=B[i+1][j];
           B[i+1][j]=exchange;
   	  	 }
   	  }
   	  else
   	  {  rate=(1.0*A_down[i])/A_mid[i];
   	  	 A_mid[i+1]=A_mid[i+1]-rate*A_up[i];
   	     A_down[i]=A_down[i]-rate*A_mid[i];
         for(j=0;j<n;j++)
      	   B[i+1][j]=B[i+1][j]-rate*B[i][j];
   	  }
   }
   for(i=m-2;i>=0;i--)
   {  rate=(1.0*A_up[i])/A_mid[i+1];
      A_up[i]=A_up[i]-rate*A_mid[i+1];
   	  for(j=0;j<n;j++)
   	  	B[i][j]=B[i][j]-rate*B[i+1][j];
   } 
   for(i=m-3;i>=0;i--)
   { if(A_up_up==0)
   	   continue;
   	  else
   	  { rate=(A_up_up[i]*1.0)/A_mid[i+2];
   	  	A_up_up[i]=A_up_up[i]-rate*A_mid[i+2];
   	  	for(j=0;j<n;j++)
   	  	B[i][j]=B[i][j]-rate*B[i+2][j];
   	  }
   }
   for(i=0;i<m;i++)
   {  for(j=0;j<n;j++)
   	    B[i][j]=B[i][j]/A_mid[i];
   	  A_mid[i]=1;
   }
   for(i=0;i<n;i++)
   {  for(j=0;j<m;j++)
   	   printf("%.6f ", B[j][i]);
   	  printf("\n");
   }
   return 0;
}