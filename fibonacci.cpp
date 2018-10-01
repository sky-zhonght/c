#include <stdio.h>
#include <cstring>
#include <malloc.h>
struct matrix
{  int a[2][2];
   matrix(){memset(a, 0 , sizeof a);}
};
matrix mat1,mat2,mat3;
matrix operator *(matrix A,matrix B)
{  matrix C;
   for(int i=0;i<=1;++i)
   {  for(int j=0;j<=1;++j)
      {  for(int k=0;k<=1;++k)
	     C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%9973;
	  }   
   }
   return C;
}
void fun1(int n)
{  int i;
   int s=n;
   int *a;
   for(i=0;s>0;i++)
  {  s=s/2;
  }
  i=i-1;
  s=n;
  a=(int *)malloc(sizeof(int)*i);
  for(int j=0;j<i;j++)
  {  if(s%2==1)
     a[i-1-j]=1;
     else
     a[i-1-j]=0;
     s=s/2;
  }
  for(int k=0;k<i;k++)
  {  mat3=mat3*mat3;
     if(a[k]==1)
     mat3=mat3*mat2;
  }
}
int main()
{  int n,x;
   mat1.a[0][0]=1,mat1.a[0][1]=0;
   mat1.a[1][0]=0,mat1.a[1][1]=0;
   mat2.a[0][0]=1,mat2.a[0][1]=1;
   mat2.a[1][0]=1,mat2.a[1][1]=0;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {  mat3=mat2;
      scanf("%d",&x);
      fun1(x-1);
      mat3=mat3*mat1;
      printf("%d\n",mat3.a[0][0]);
   }
   return 0;
} 
