#include <stdio.h>
#include <malloc.h>
int main()
{
	short int N, K, U, i, j, k, pin1, pin2, s, t;
	int x;
	short int *index, *Friend, *max;
	bool **matrix;
	scanf("%hd%hd%hd",&N,&K,&U);
	index = (short int*)malloc(sizeof(short int)*(N - 1));
	matrix = (bool**)malloc(sizeof(bool*)*N);
	matrix[0] = (bool*)malloc(sizeof(bool) * 1);
	matrix[0][0] = true;
	pin1 = -1;
	pin2 = N - 1;
	index[0] = 0;
	for (i = 1; i<N; i++)
	{
		matrix[i] = (bool*)malloc(sizeof(bool)*i);
		if (i < N - 1)
			index[i] = 0;
	}
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			scanf("%d",&x);
			if (i <= j)
				continue;
			else
				matrix[i][j] = x;
		}
	}
	for (i = N - 1; i >= 0; i--)
	{
		if (i == U)
			continue;
		else if (i>U)
		{
			if (matrix[i][U] == true)
			{
				pin1++;
				index[pin1] = i;
			}
			else if (matrix[i][U] == false)
			{
				pin2--;
				index[pin2] = i;
			}
		}
		else
		{
			if (matrix[U][i] == true)
			{
				pin1++;
				index[pin1] = i;
			}
			else if (matrix[U][i] == false)
			{
				pin2--;
				index[pin2] = i;
			}
		}
	}
	if (pin2 == N - 1)
		return 0;
	else
	{
		Friend = (short int*)malloc(sizeof(short int)*(N - 1 - pin2));
		for (i = 0; i < N - 1 - pin2; i++)
		{
			Friend[i] = 0;
		}
		for (k = pin2; k<N - 1; k++)
		{
			s = 0;
			for (i = pin1; i >= 0; i--)
			{
				if (index[k]>index[i])
				{
					if (matrix[index[k]][index[i]] == true)
						s = s + 1;
					else continue;
				}
				if (index[k]<index[i])
				{
					if (matrix[index[i]][index[k]] == true)
						s = s + 1;
					else continue;
				}
			}
			if (s >= K)
			{
				Friend[k - pin2] = s;
			}
			else
			{
				Friend[k - pin2] = -1;
			}
        }
		for (i = 0; i<N; i++)
			free(matrix[i]);
		free(matrix);
		max = (short int*)malloc(sizeof(short int)*(N - 1 - pin2));
		for (i = 0; i<N - 1 - pin2; i++)
			max[i] = Friend[i];
		for (i = 0; i<N - 1 - pin2; i++)
		{
			for (j = i + 1; j<N - 1 - pin2; j++)
			{
				if (max[j] < max[i])
				{
					t = max[j];
					max[j] = max[i];
					max[i] = t;
				}
			}
		}
		for (i = N - pin2 - 1; i >= 0; i--)
		{
			if (max[i] == -1)
				continue;
			else
				for (j = pin2; j < N - 1; j++)
				{
					if (i < N - pin2 - 1 && max[i] == max[i + 1])
						continue;
					else
						if (max[i] == Friend[j - pin2])
							printf("%hd ", index[j]);
				}
		}
		printf("\n");
		return 0;
	}
}