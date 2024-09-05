#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
        {
        largest = right;
    }

    if (largest != i)
        {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int>& arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        {
        heapify(arr, n, i);
    }
}

void heapSort(vector<int>& arr, int n)
 {
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--)
        {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        {
        cout << arr[i] << " ";
    }
    cout<< endl;
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int n = arr.size();

    cout<< "Unsorted array: ";
    printArray(arr);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
