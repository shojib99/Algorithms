#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10, 12, 14};
    int x = sizeof(arr1) / sizeof(arr1[0]);
    int y = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[30];
    int i = 0, j = 0, k = 0;
    
    while (i < x && j < y) {
        if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
            k++;
        } else {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    
    if (i < x) {
        for (int m = i; m < x; m++) {
            arr3[k] = arr1[m];
            k++;
        }
    } else {
        for (int m = j; m < y; m++) {
            arr3[k] = arr2[m];
            k++;
        }
    }
    
    for (int l = 0; l < (x + y); l++) {
        cout << arr3[l] << " ";
    }
    
    return 0;
}

