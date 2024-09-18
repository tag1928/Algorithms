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
	
	while (left_cursor < left_array.size() and right_cursor < right_array.size())
	{
		if (left_array[left_cursor] < right_array[right_cursor])
		{
			array[cursor] = left_array[left_cursor];
			
			cursor += 1;
			left_cursor += 1;
		}
		
		else
		{
			array[cursor] = right_array[right_cursor];
			
			cursor += 1;
			right_cursor += 1;
		}
	}
	
	while (left_cursor < left_array.size())
	{
		array[cursor] = left_array[left_cursor];
		
		cursor += 1;
		left_cursor += 1;
	}
	
	while (right_cursor < right_array.size())
	{
		array[cursor] = right_array[right_cursor];
		
		cursor += 1;
		right_cursor += 1;
	}
}

void mergeSort(vector <int> &array)
{
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
	cout << "Enter the size of the array: " << endl;
	int arraySize;
	cin >> arraySize;
	
	cout << "Enter the elements of array: " << endl;
	int arr[arraySize];
	vector <int> array(arraySize);
	
	for (int i = 0; i < arraySize; i++)
	{
		cin >> arr[i];
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
