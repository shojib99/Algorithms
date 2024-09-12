#include <bits/stdc++.h>
using namespace std;

void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    int count=1;
    cout <<" The solution set :"<< endl;
    i = 0;
    cout <<" "<< i+1;
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            count++;
            cout <<"\t" << j+1;

            i = j;

        }
    }
    cout << "\n\n";
    cout << count;
}

int main()
{
   int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12,15};
   int f[] = {4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 18};

        int n = sizeof(s)/sizeof(s[0]);

    for (int k=0; k< n; k++)
     {
         for(int l=k+1; l< n; l++)
         {
             if(f[k] > f[l]) {
               int temp = f[k];
               f[k] = f[l];
               f[l] = temp;

               temp = s[k];
               s[k] = s[l];
               s[l] = temp;
           }

         }
     }
     for (int i = 0; i < n; i++)
        {
        printf("%d ", s[i]);
    }
    cout <<"\n";
    for (int i = 0; i < n; i++)
        {
        printf("%d ", f[i]);
    }
    cout<<"\n";
    printMaxActivities(s, f, n);
    return 0;
}
