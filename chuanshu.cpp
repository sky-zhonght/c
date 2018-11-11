#include <stdio.h>
#include <string>
#include <queue>
#include <malloc.h>
using namespace std;
struct Snode
{
	long int value;
	unsigned int index;
	bool operator < (const Snode &a) const { return value > a.value; }
};
priority_queue <Snode> Q;
int n;
unsigned int *Left,*Right;
string *code;
void dfs(int i, string str)
{   
	if (i<n)
	{
		code[i] = str;
		return;
	}
	dfs(Left[i-n], str + "0");
	dfs(Right[i-n], str + "1");
}
int main()
{  scanf("%d", &n); 
   if(n==1)
    {  printf("1.000000\n");
       printf("0\n");
	}
	else
	{  long int x, sum = 0, Sum = 0, i;
	Left=(unsigned int*)malloc(sizeof(unsigned int)*(n-1));
	Right=(unsigned int*)malloc(sizeof(unsigned int)*(n-1));
	code=(string*)malloc(sizeof(string)*n);
	for (i = 0; i<n; i++)
	{
		scanf("%lld", &x);
		Snode node;
		node.index = i;
		node.value =(long int)x;
		Q.push(node);
		sum = sum + x;
	}
	for (int i = 0; i<n - 1; i++)
	{
		Snode Left_son = Q.top();
		Q.pop();
		Snode Right_son = Q.top();
		Q.pop();
		Snode Node;
		Node.index = i + n;
		Node.value = Left_son.value + Right_son.value;
		Q.push(Node);
		Left[i] = Left_son.index;
		Right[i] = Right_son.index;
		Sum = Sum + Node.value;
		
	}
	printf("%.6lf\n", float(Sum) / sum);
	dfs(2*n-2, "");
	free(Left);
	free(Right);
	for (i = 0; i<n; i++)
		printf("%s\n", code[i].c_str());
	free(code);
	return 0;
	}
}