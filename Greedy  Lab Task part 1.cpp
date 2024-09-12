#include <bits/stdc++.h>
using namespace std;

int maxNonOverlappingTalks(vector<pair<int, int>>& talks)
 {
    sort(talks.begin(), talks.end(), [](pair<int, int> a, pair<int, int> b)
         {
        return a.second < b.second;
    });

    int count = 0;
    int last_end_time = 0;

    for (const auto& talk : talks)
        {
        if (talk.first >= last_end_time)
        {
            count++;
            last_end_time = talk.second;
        }
    }

    return count;
}

int main()
 {
    int n = 5;
    vector<pair<int, int>> talks = {{1, 3}, {2, 5}, {4, 7}, {1, 8}, {5, 9}};

    int result = maxNonOverlappingTalks(talks);

    cout << "Maximum non-overlapping talks: " << result << endl;

    return 0;
}
