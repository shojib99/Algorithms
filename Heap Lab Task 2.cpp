#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i)
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
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr, int n)
 {
    for (int i = n / 2 - 1; i >= 0; i--)
        {
        maxHeapify(arr, n, i);
    }
}

void printHeap(vector<int>& arr)
 {
    for (int i = 0; i < arr.size(); i++)
        {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
 {
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = arr.size();

    cout<< "Min Heap: ";
    printHeap(arr);

    buildMaxHeap(arr, n);

    cout<< "Max Heap: ";
    printHeap(arr);

    return 0;
}
