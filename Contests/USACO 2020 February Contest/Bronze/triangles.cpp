#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("triangles.out");
    ifstream fin("triangles.in");
    int N;
    fin >> N;
    vector<pair<int, int>> posts(N);
    for (int i = 0; i < N; i++)
        fin >> posts[i].first >> posts[i].second;
    int maxArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (posts[i].second != posts[j].second)
                continue;
            for (int k = 0; k < N; k++) {
                if (i == k || j == k)
                    continue;
                if (posts[i].first != posts[k].first)
                    continue;
                maxArea = max(maxArea, abs(posts[i].first - posts[j].first) * abs(posts[i].second - posts[k].second));
            }
        }
    }
    fout << maxArea << '\n';

    return 0;
}