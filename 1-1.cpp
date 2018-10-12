#include <stdio.h>
#include <math.h>
#include <malloc.h>
float Distance(float x1, float y1, float x2, float y2)
{
	return(sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}
float short_Distance(float x0, float y0, float x1, float y1, float x2, float y2)
{
	return(abs((y1 - y2)*x0 - (x1 - x2)*y0 - x2 * y1 + x1 * y2) / sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}
int main()
{
	int N;
	scanf("%d", &N);
	float *a;
	for (int i = 0; i<N; i++)
	{
		a = (float *)malloc(sizeof(float) * 9);
		for (int j = 0; j<9; j++)
		{
			scanf("%f", &a[j]);
		}
		if ((a[0] - Distance(a[1], a[2], a[3], a[4]))*(a[0] - Distance(a[1], a[2], a[5], a[6])) <= 0)
		{
			printf("%d\n", 1);
			free(a);
			continue;
		}
		else if ((a[0] - Distance(a[1], a[2], a[3], a[4]))*(a[0] - short_Distance(a[1], a[2], a[3], a[4], a[5], a[6])) <= 0)
		{
			if (((a[4] - a[2])*(a[4] - a[6]) + (a[3] - a[5])*(a[3] - a[1]))*((a[6] - a[2])*(a[4] - a[6]) + (a[3] - a[5])*(a[5] - a[1]))<0)
			{
				printf("%d\n", 1);
				free(a);
				continue;
			}
		}
		if ((a[0] - Distance(a[1], a[2], a[3], a[4]))*(a[0] - Distance(a[1], a[2], a[7], a[8])) <= 0)
		{
			printf("%d\n", 1);
			free(a);
			continue;
		}
		else if ((a[0] - Distance(a[1], a[2], a[3], a[4]))*(a[0] - short_Distance(a[1], a[2], a[3], a[4], a[7], a[8])) <= 0)
		{
			if (((a[4] - a[2])*(a[4] - a[8]) + (a[3] - a[7])*(a[3] - a[1]))*((a[8] - a[2])*(a[4] - a[8]) + (a[3] - a[7])*(a[7] - a[1]))<0)
			{
				printf("%d\n", 1);
				free(a);
				continue;
			}
		}
		if ((a[0] - Distance(a[1], a[2], a[7], a[8]))*(a[0] - Distance(a[1], a[2], a[5], a[6])) <= 0)
		{
			printf("%d\n", 1);
			free(a);
			continue;
		}
		else if ((a[0] - Distance(a[1], a[2], a[7], a[8]))*(a[0] - short_Distance(a[1], a[2], a[7], a[8], a[5], a[6])) <= 0)
		{
			if (((a[6] - a[2])*(a[6] - a[8]) + (a[5] - a[7])*(a[5] - a[1]))*((a[8] - a[2])*(a[6] - a[8]) + (a[5] - a[7])*(a[7] - a[1]))<0)
			{
				printf("%d\n", 1);
				free(a);
				continue;
			}
		}
		printf("%d\n", 0);
		free(a);
	}
	return 0;
}

