#include "sort.h"

/**
  * swap - swaps two ints
  *@array: array to sort
  *@size: size of array
  *@a: input
  *@b: input
  * Return: void
  **/

void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
  * lomuto - partitions an array
  * @array: array to partition
  * @size: size of array
  * @low: lowest index
  * @high: highest index
  * Return: size_t
  **/
size_t lomuto(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot = array[high];

	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
		{
			swap(array, size, &array[j], &array[i++]);
		}
	swap(array, size, &array[i], &array[high]);

	return (i);
}

/**
  * quick_s - quick sorts via Lomuto
  * @array: array to partition
  * @size: size of array
  * @low: lowest index
  * @high: highest index
  * Return: void
  **/
void quick_s(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = lomuto(array, size, low, high);

		quick_s(array, size, low, p - 1);
		quick_s(array, size, high, p + 1);
	}
}

/**
  * quick_sort - quick sorts array
  * @array: array
  * @size: size of the array
  * Return: void
  **/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_s(array, size, 0, size - 1);
}
