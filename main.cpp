#include"sort_algorithms.cpp"

int main()
{
	int arr[] = {5,2,8,6,51,10,22,1,60,3};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	count_sort(arr,size);
	//heap_sort(arr,size);
	//bubble_sort(arr,size);
	//selection_sort(arr,size);
	//merge_sort(arr,0,size-1);
	//insertion_sort(arr,size);
	print_arr(arr,size);
	
	return 0;
}
