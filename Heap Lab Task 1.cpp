#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;

    cout<< "Enter the size of the binary heap: ";
    cin >>N;
    int height =ceil(log2(N + 1)) - 1;

    cout<< "The height of the binary heap is: " << height <<endl;

    return 0;
}
