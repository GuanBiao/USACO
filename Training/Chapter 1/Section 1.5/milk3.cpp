/*
ID: xup6ej01
PROG: milk3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int A, B, C;
set<int> ans;
set<vector<int>> state;

void solve(int a, int b, int c) {
    if (state.count({a, b, c}) == 1)
        return;
    state.insert({a, b, c});

    if (a == 0) {
        ans.insert(c);
    } else {
        if (B > b) {
            int a_used = min(a, B - b);
            solve(a - a_used, b + a_used, c);
        }
        if (C > c) {
            int a_used = min(a, C - c);
            solve(a - a_used, b, c + a_used);
        }
    }

    if (b != 0) {
        if (A > a) {
            int b_used = min(b, A - a);
            solve(a + b_used, b - b_used, c);
        }
        if (C > c) {
            int b_used = min(b, C - c);
            solve(a, b - b_used, c + b_used);
        }
    }

    if (c != 0) {
        if (A > a) {
            int c_used = min(c, A - a);
            solve(a + c_used, b, c - c_used);
        }
        if (B > b) {
            int c_used = min(c, B - b);
            solve(a, b + c_used, c - c_used);
        }
    }
}

int main() {
    ofstream fout("milk3.out");
    ifstream fin("milk3.in");
    fin >> A >> B >> C;
    solve(0, 0, C);
    set<int>::iterator it = ans.begin();
    fout << *it;
    for (it++; it != ans.end(); it++)
        fout << ' ' << *it;
    fout << '\n';
    return 0;
}