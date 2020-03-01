/*
ID: xup6ej01
PROG: wormhole
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int N, cnt = 0;
vector<pair<int, int>> wormholes(12);
int pairing[12];

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

bool isTrapped() {
    for (int i = 0; i < N; i++) { // start from the position of every wormhole
        pair<int, int> pos = wormholes[i];
        while (1) {
            bool changed = false;
            for (int j = 0; j < N; j++) { // check if any wormhole is in front of the current position
                if (wormholes[j].first > pos.first && wormholes[j].second == pos.second) {
                    pos = wormholes[pairing[j]]; // exit from the other wormhole in the pairing
                    changed = true;
                    if (pos == wormholes[i]) // true means Bessie travels back to the starting position
                        return true;
                    break;
                }
            }
            if (!changed) // true means Bessie won't get stuck if starting from wormhole i
                break;
        }
    }
    return false;
}

void solve(int startPair) {
    if (startPair == N / 2) {
        cnt += isTrapped();
        return;
    }

    for (int i = 0; i < N; i++) {
        if (pairing[i] == -1) {
            for (int j = i + 1; j < N; j++) {
                if (pairing[j] == -1) {
                    pairing[i] = j;
                    pairing[j] = i;
                    solve(startPair + 1);
                    pairing[i] = -1;
                    pairing[j] = -1;
                }
            }
            break;
        }
    }
}

int main() {
    ofstream fout("wormhole.out");
    ifstream fin("wormhole.in");
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> wormholes[i].first >> wormholes[i].second;
        pairing[i] = -1;
    }
    sort(wormholes.begin(), wormholes.begin() + N, comp);
    solve(0);
    fout << cnt << '\n';
    return 0;
}