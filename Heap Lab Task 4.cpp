#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
        {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallest(vector<int>& arr, int low, int high, int k)
 {
    if (k > 0 && k <= high - low + 1)
        {
        int pi = partition(arr, low, high);

        if (pi - low + 1 == k)
            {
            return arr[pi];
        }
        else if
            (pi - low + 1 > k)
             {
            return kthSmallest(arr, low, pi - 1, k);
        }
        else
            {
            return kthSmallest(arr, pi + 1, high, k - pi + low - 1);
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int n = arr.size();
    int k = 3;

    cout<< "K'th smallest element: " << kthSmallest(arr, 0, n - 1, k) <<endl;

    return 0;
}
