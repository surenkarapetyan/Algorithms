#include<iostream>
#include <vector>
#include <algorithm>
#include"sort_algorithms.hpp"

void insertion_sort(int arr[], int n)
{
	int j, key;
	for(int i = 1; i < n; ++i) {
		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}	
}

void merge(int arr[], int l, int m, int r)
{
	int i,j,k;

	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1];
	int R[n2];

	for(i = 0; i < n1; ++i)
		L[i] = arr[l + i];

	for(j = 0; j < n2; ++j)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j] )
		{
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = l + (r-l)/2;

		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void selection_sort(int arr[], int n)
{
	int i,j,min_index;

	for(i = 0; i < n-1; ++i) {
		min_index = i;
		for(j = i+1; j < n; ++j)
			if(arr[j] < arr[min_index])
				min_index = j;
	
		swap(&arr[min_index], &arr[i]);
	}
}

void bubble_sort(int arr[], int n)
{
	int i, j;
	bool swapped;

	for(i = 0; i < n-1; ++i){
		swapped = false;
		for(j = 0; j < n-i-1; ++j){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; j < high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }

}

void count_sort(int arr[], int n)
{
    int max = *std::max_element(&arr[0], &arr[n-1]);
    int min = *std::min_element(&arr[0], &arr[n-1]);
    int range = max - min + 1 ;
	int z = 0;

	int count[n], output[n+1];
	
	for(int i = min; i <= max; ++i)
		count[i] = 0;

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

	for(int i = min; i <= max; i++) {
		while(count[i]-- > 0) arr[z++] = i;
	}
	
    //for(int i = 1; i < max; i++)
    //    count[i] += count[i-1];

    //for(int i = n; i >= 1; i--) {
    //    output[count[arr[i]]] = arr[i];
    //    count[arr[i]]--;
    //}

    //for(int i = 0; i < n; i++)
    //    arr[i] = output[i];
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && arr[l] > arr[largest])
		largest = l;

	if(r < n && arr[r] > arr[largest])
		largest = r;

	if(largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, i);
	}

}

void heap_sort(int arr[], int n)
{
	for(int i = n/2-1; i >= 0; i--)
		heapify(arr, n, i);

	for(int i = n-1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void print_arr(int arr[], int n)
{
	for(int i = 0; i < n; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}
