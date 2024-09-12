#include <bits/stdc++.h>
using namespace std;

struct Package
{
    int reach;
    int cost;
    double reachPerCost;
};

bool compareByRatio(Package a, Package b)
{
    return a.reachPerCost > b.reachPerCost;
}

double maxReach(vector<pair<int, int>>& packages, int W)
{
    vector<Package> packageList;

    for (const auto& p : packages)
        {
        packageList.push_back({p.first, p.second, (double)p.first / p.second});
    }

    sort(packageList.begin(), packageList.end(), compareByRatio);

    double totalReach = 0.0;
    int currentBudget = W;

    for (const auto& pkg : packageList)
        {
        if (currentBudget >= pkg.cost)
        {
            totalReach += pkg.reach;
            currentBudget -= pkg.cost;
        }

        else
            {
            totalReach += pkg.reachPerCost * currentBudget;
            break;
        }
    }

    return totalReach;
}

int main()
{
    int m = 4;
    vector<pair<int, int>> packages = {{500, 100}, {800, 150}, {2000, 300}, {1200, 200}};
    int W = 400;

    double result = maxReach(packages, W);

    cout << "Maximum Reach: " << result << " people" << endl;

    return 0;
}
