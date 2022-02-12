//Implementation of a bubble sort
#include <iostream>

using namespace std;

//Prototype functions to use
void swap(int* xp, int* yp);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int size);

//Driver code
int main()
{
	int arr[] = {50, 31, 21, 28, 72, 41, 73, 93, 68, 43, 45, 78, 5, 17, 97, 71, 69, 61, 88, 75, 99, 44, 55, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	//Call the bubble sort and print the array
	bubbleSort(arr, n);
	cout << "\nBubble Sorted array: \n";
	printArray(arr, n);

	//Call the selection sort and print the array
	selectionSort(arr, n);
	cout << "\nSelection Sorted array: \n";
	printArray(arr, n);

	//Call the insertion sort and print the array
	insertionSort(arr, n);
	cout << "\nInsertion Sorted array: \n";
	printArray(arr, n);
	return 0;
}

//Swap function
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Bubble sort function
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			swap(&arr[j], &arr[j + 1]);
		}
	}
}

//Print array function
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Implementation differences of a selection sort
//This function replaces the "bubbleSort" function
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	//One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		//Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}

		swap(&arr[min_idx], &arr[i]);
	}
}

//Implementation differences of the insertion sort
//Insertion does not use the swap function
//Print will be the exact same
//Insert sort function
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		//Move elements of arr[], that are greater than key, 
		//to one position ahead of their current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	
}