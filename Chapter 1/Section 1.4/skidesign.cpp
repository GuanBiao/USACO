/*
ID: xup6ej01
PROG: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("skidesign.out");
    ifstream fin("skidesign.in");
    int N;
    fin >> N;
    vector<int> hills(N);
    for (int i = 0; i < N; i++)
        fin >> hills[i];
    sort(hills.begin(), hills.end());

    int minCost = INT_MAX;
    for (int x = 0; ; x++) {
        int cost = 0;

        int newLowest = hills.front() + x;
        for (int i = 0; i < N && hills[i] < newLowest; i++)
            cost += (newLowest - hills[i]) * (newLowest - hills[i]);

        int newHighest = hills.back();
        for (; newHighest - newLowest > 17; newHighest--);
        for (int i = N - 1; i >= 0 && hills[i] > newHighest; i--)
            cost += (hills[i] - newHighest) * (hills[i] - newHighest);

        if (minCost < cost)
            break;
        minCost = cost;
    }
    fout << minCost << '\n';

    return 0;
}