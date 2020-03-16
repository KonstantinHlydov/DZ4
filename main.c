#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define for_i for(int i = 0; i < r; i++)

int summ(int* arr, int r, int c, int i)
{
	printf("Vvivod massiva:\n");
	int f = 0;
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			f = f + *(arr + i + i * c + j);
			*(arr + i + i * c + c) = f;
		}
		f = 0;
	}
}

void swap(int* a, int* b)
{
	int z = *a;
	*a = *b;
	*b = z;
}

void sort(int* arr, int r, int c, int i)
{
	for (int q = 0; q < c; q++)
	{
		for_i
		{
		for (int j = 1; j < r; j++)
		{
			if (*(arr + i + i * c + j) < *(arr + i + i * c + j - 1))
			{
				swap(&*(arr + i + i * c + j), &*(arr + i + i * c + j - 1));
			}
		}
		}
	}
}

int print(int* arr, int c, int r)
{
	int q = 0;
	for_i
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(arr + i * c + j));
			q++;
			if (q == c)
			{
				q = 0;
				printf("\n");
			}
		}
	}
}

int main()
{
	int r = 3, c = 4;
	int i = 0;
	int* arr = (int*)malloc(r * c * sizeof(int));
	for_i
		for (int j = 0; j < (c - 1); j++)
		{
			*(arr + i * c + j) = rand() % 3;
		}
	for_i
	{
		int j = (c - 1);
		*(arr + i * c + j) = 0;
	}
	print(&*arr, c, r);
	summ(&*arr, c, r, i);
	print(&*arr, c, r);
	sort(&*arr, c, r, i);
	printf("Itog sortirovki:\n");
	print(&*arr, c, r);
	free(arr);
}
