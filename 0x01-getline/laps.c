#include "laps.h"
/*
*/
void doublesort(int *cars, int *laps, int index)
{
	int aux;
	int i;
	for (i = index; i > 0; i--)
	{
		if (cars[i] < cars[i - 1])
		{
			aux = cars[i - 1];
			cars[i - 1] = cars[i];
			cars[i] = aux;
			aux = laps[i - 1];
			laps[i - 1] = laps[i];
			laps[i] = aux;
		}
	}
}
void race_state(int *id, size_t size)
{
    int cars[100];    
    int laps[100];
	static size_t index = 0;
	int found;
	size_t i, j;
	if (!size)
		return;
	for (i = 0; i < size; i++)
	{
		found = 0;
		for (j = 0; j < index; j++)
		{
			if (id[i] == cars[j])
			{
				found = 1;
				laps[j] += 1;
			}
		}
		if (found == 0)
		{

			cars[index] = id[i];
			doublesort(cars, laps, index);
            index++;
            printf("Car %d joined the race\n", id[i]);
		}
	}
	printf("Race state:\n");
	for (j = 0; j < index; j++)
	{
		printf("Car %d [%d laps]\n", cars[j], laps[j]);
	}
}
