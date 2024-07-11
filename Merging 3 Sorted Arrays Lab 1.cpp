#include <bits/stdc++.h>
using namespace std;

void mergeThreeSortedArray(int arr1[], int n1, int arr2[], int n2, int arr3[], int n3, vector<int>& result) 
{
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2 && k < n3)
    {
        if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) 
        {
            result.push_back(arr1[i]);
            i++;
        } 
        else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k])
        {
            result.push_back(arr2[j]);
            j++;
        } 
        else
        {
            result.push_back(arr3[k]);
            k++;
        }
    }
    
    while (i < n1 && j < n2) 
    {
        if (arr1[i] <= arr2[j]) 
        {
            result.push_back(arr1[i]);
            i++;
        } 
        else 
        {
            result.push_back(arr2[j]);
            j++;
        }
    }
    
    while (j < n2 && k < n3) 
    {
        if (arr2[j] <= arr3[k]) 
        {
            result.push_back(arr2[j]);
            j++;
        } 
        else 
        {
            result.push_back(arr3[k]);
            k++;
        }
    }
    
    while (i < n1 && k < n3)
    {
        if (arr1[i] <= arr3[k]) 
        {
            result.push_back(arr1[i]);
            i++;
        } 
        else
        {
            result.push_back(arr3[k]);
            k++;
        }
    }
    
    while (i < n1)
    {
        result.push_back(arr1[i]);
        i++;
    }
    
    while (j < n2) 
    {
        result.push_back(arr2[j]);
        j++;
    }
    
    while (k < n3) 
    {
        result.push_back(arr3[k]);
        k++;
    }
}

int main() 
{
    int arr1[] = {1, 5, 9};
    int arr2[] = {2, 6, 10, 14};
    int arr3[] = {3, 7, 8, 11, 15};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    vector<int> result;
    mergeThreeSortedArray(arr1, n1, arr2, n2, arr3, n3, result);
    
    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i] << " ";
    }
    
    return 0;
}
