#include <iostream>
#include <vector>

using namespace std;

void printArray(vector <int> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";
	}
	
	cout << endl;
	
	return;
}

void merge(vector <int> &left_array, vector <int> &right_array, vector <int> &array)
{
	int left_cursor = 0;
	int right_cursor = 0;
	int cursor = 0;
}

void mergeSort(vector <int> &array)
{
	printArray(array);
	if (array.size() <= 1) return;
	
	int left_array_size = array.size() / 2;
	int right_array_size = array.size() - left_array_size;
	
	vector <int> left_array(left_array_size);
	vector <int> right_array(right_array_size);
	
	for (int i = 0; i < left_array_size; i++)
	{
		left_array[i] = array[i];
	}
	
	for (int i = 0; i < right_array_size; i++)
	{
		right_array[i] = array[i + left_array_size];
	}
	
	mergeSort(left_array);
	mergeSort(right_array);
	merge(left_array, right_array, array);
}

int main()
{
	int arraySize = 5;
	vector <int> array(arraySize);
	
	//  {10, 7, 2, 3, 9, 8, 1, 5, 0, 4};
	
	int arr[] = {5, 4, 3, 2, 1};
	
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = arr[i];
	}
	
	cout << "Unsorted array: " << endl;
	printArray(array);
	cout << endl;
	
	cout << "Sorted array: " << endl;
	mergeSort(array);
	printArray(array);
	cout << endl;
}
