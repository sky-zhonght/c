#include <stdio.h>
#include <algorithm>
#include <malloc.h>
using namespace std;
int main()
{
	int *A, x,*D;
	unsigned int **yang;
	int N, N1, N2, N3, i, j, row, column,s;
	row = 0;
	bool zero = false;
	int C[1000];
	scanf("%d%d%d%d", &N, &N1, &N2, &N3);
	A = (int*)malloc(sizeof(int)*(N+N2));
	for (i = 0; i<N; i++)
	{
		scanf("%d", &A[i]);
		if (A[i] == -1)
		{
			C[row] = i;
			row = row + 1;
		}
	}
	yang = (unsigned int**)malloc(sizeof(unsigned int*)*row);
	yang[0] = (unsigned int*)malloc(sizeof(unsigned int)*C[0]);
	for (i = 0; i<C[0]; i++)
		yang[0][i] = A[i];
	for (i = 1; i<row; i++)
	{
		yang[i] = (unsigned int*)malloc(sizeof(unsigned int)*(C[i] - C[i - 1] - 1));
		for (j = C[i - 1] + 1; j<C[i]; j++)
			yang[i][j - C[i - 1] - 1] = A[j];
	}
	for (i = 0; i<N1; i++)
	{   scanf("%d",&x); 
		column = C[0] - 1;
		j = 0;
		zero = false;
		while (j<row)
		{
			if (x>yang[j][column])
			{
				j++;
				if (column>C[j] - C[j - 1] - 2)
					column = C[j] - C[j - 1] - 2;
			}
			else if (x<yang[j][column])
			{
				if (column>0)
					column = column - 1;
				else break;
			}
			else
			{
				printf("%d %d ", j, column);
				zero = true;
				break;
			}
		}
		if (zero == false)
			printf("%d %d ", -1, -1);
	}
	printf("\n");
	for (i = C[0]; i<C[0] + N2; i++)	
	{    scanf("%d",&x);
        A[i-C[0]+N]=x;
	}
	sort(A,A+N+N2);
	s=0;
	for(i=0;i<N+N2;i++)
	{ if(A[i]>0)
       printf("%d ", A[i]);
      else  s=s+1;
	}
	printf("%d\n",-1);
	D=(int*)malloc(sizeof(int)*N3);
	for(i=0;i<N3;i++)
	  scanf("%d",&D[i]);
	sort(D,D+N3); 
	i=0;
	while(i<=N3)
	{  if(i==N3&&s<N+N2-1)
	   {  for(i=s;i<N+N2;i++)
	       printf("%d ", A[i]);
	      i=i+1;
       }
       else
       {   for(j=s;j<N+N2;j++)
		{  if(A[j]==D[i])
			{   A[j]=-1;
				i=i+1;
				s=j+1;
				break;
			}
			else printf("%d ", A[j]);
		}
	   }
	}
	printf("%d\n",-1);
	return 0;
}

