#include <stdio.h>
int main()
{  int node[21000];
   int index[21000];
   int N,M,K,T,i,j,k;
   int delete_position,insert_value,insert_position,insert_random;
   scanf("%d%d%d%d",&N,&M,&K,&T);
   for(i=0;i<N;i++)
     scanf("%d",&node[i]);
   for(i=0;i<N;i++)
   	 scanf("%d",&index[i]);
   for(i=0;i<M;i++)
   	{  scanf("%d",&delete_position);
   	   if(delete_position>=N)
   	   continue;
   	   else
   	   {  for(j=0;j<N;j++)
       	   {  if(index[j]==delete_position)
       	   	   index[j]=-1;
       	   	  else if(index[j]>delete_position)
       	   	   index[j]=index[j]-1;
       	   }
       	   for(k=delete_position;k<N-1;k++)
       	   {  node[k]=node[k+1];
       	   	  index[k]=index[k+1];
           }
           node[N-1]=0;
           index[N-1]=-1;
       	   N=N-1;
	   }
   	}
   for(i=0;i<K;i++)
   	{  scanf("%d%d%d",&insert_value,&insert_position,&insert_random);
   	     if(insert_position>N)
          continue;
          else
          {  for(j=0;j<N;j++)
         {  if(index[j]>=insert_position)
            index[j]=index[j]+1;
         }
         for(j=N;j>insert_position;j--)
         {  node[j]=node[j-1];
            index[j]=index[j-1];
         }
           node[insert_position]=insert_value;
           index[insert_position]=insert_random;
           N=N+1; 
          }
   	}
    for(i=T;i<N;i++)
   	  printf("%d ",node[i]);
   	printf("%d\n",-1);
    j=T;
   	if(T>=N)
   	  printf("%d\n",-1); 
	else
	{  while(index[j]>=0)
   	{  printf("%d ",node[j]);
       j=index[j];
   	}
   	printf("%d -1\n",node[j]);
	}
   	return 0;
}
