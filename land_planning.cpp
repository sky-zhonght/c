#include <stdio.h>
#include <malloc.h>
using namespace std;
int main()
{
	int N, K, *area, *inv_area, *index_value, *h, *index_position;
	int i, j, pin, max_area;
	max_area = 0;
	scanf("%d%d",&N,&K);
	h = (int*)malloc(sizeof(int)*N);
	index_value = (int*)malloc(sizeof(int)*(N + 1));
	index_position = (int*)malloc(sizeof(int)*(N + 1));
	area = (int*)malloc(sizeof(int)*N);
	inv_area = (int*)malloc(sizeof(int)*N);
	for (i = 0; i<N; i++)
	{
		scanf("%d",&h[i]);
		area[i] = inv_area[i] = 0;
	}
	for (i = 0; i <= N; i++)
		index_value[i] = index_position[i] = -1;
	pin = 0;
	for (i = 0; i<N; i++)
	{
		while (h[i]<index_value[pin])
		{
			pin = pin - 1;
		}
		pin = pin + 1;
		index_position[pin] = i;
		index_value[pin] = h[i];
		for (j = 1; j <= pin; j++)
		{
			if (max_area<(index_position[pin] - index_position[j - 1])*index_value[j])
				max_area = (index_position[pin] - index_position[j - 1])*index_value[j];
			else
				continue;
		}
		area[i] = max_area;
	}
	pin = 0;
	index_position[0] = N;
	max_area = 0;
	for (i = N - 1; i >= 0; i--)
	{
		while (h[i]<index_value[pin])
		{
			pin = pin - 1;
		}
		pin = pin + 1;
		index_position[pin] = i;
		index_value[pin] = h[i];
		for (j = 1; j <= pin; j++)
		{
			if (max_area<(index_position[j - 1] - index_position[pin])*index_value[j])
				max_area = (index_position[j - 1] - index_position[pin])*index_value[j];
			else
				continue;
		}
		inv_area[i] = max_area;
	}
	for (i = 0; i<N - 1; i++)
	{
		if (area[i + 1]<area[i])
			area[i + 1] = area[i];
	}
	for (i = N - 1; i >= 1; i--)
	{
		if (inv_area[i]<inv_area[i - 1])
			inv_area[i] = inv_area[i - 1];
	}
	max_area = 0;
	for (i = 0; i<N-K-1; i++)
	{
		if (max_area<area[i] + inv_area[i + K + 1])
			max_area = area[i] + inv_area[i + K + 1];
	}
	printf("%d",max_area);
	return 0;
}
