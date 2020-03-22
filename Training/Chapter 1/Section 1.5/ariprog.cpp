/*
ID: xup6ej01
PROG: ariprog
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout("ariprog.out");
    ifstream fin("ariprog.in");
    int N, M;
    fin >> N >> M;

    int bound = M * M * 2;
    vector<bool> isBisquare(bound + 1, false);
    for (int p = 0; p <= M; p++) {
        for (int q = 0; q <= M; q++)
            isBisquare[p * p + q * q] = true;
    }

    vector<int> bisquare;
    for (int a0 = 0; a0 <= bound; a0++) {
        if (isBisquare[a0])
            bisquare.push_back(a0);
    }

    map<int, vector<int>> m;
    for (int i = 0; i < bisquare.size(); i++) {
        for (int j = i + 1; j < bisquare.size(); j++) {
            int b = bisquare[j] - bisquare[i], n = 2;
            for (int ai = bisquare[j] + b; ai <= bound && isBisquare[ai] && n < N; ai += b, n++);
            if (n == N)
                m[b].push_back(bisquare[i]);
        }
    }

    if (m.empty())
        fout << "NONE\n";
    else {
        for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
            for (int a0 : it->second)
                fout << a0 << ' ' << it->first << '\n';
        }
    }

    return 0;
}