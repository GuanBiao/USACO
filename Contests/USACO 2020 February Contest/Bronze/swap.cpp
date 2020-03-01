#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("swap.out");
    ifstream fin("swap.in");
    int N, K, A1, A2, B1, B2;
    fin >> N >> K >> A1 >> A2 >> B1 >> B2;
    vector<int> original(N + 1), reversed(N + 1);
    for (int i = 1; i <= N; i++)
        reversed[i] = original[i] = i;
    A2++;
    B2++;
    int cnt = 0;
    for (int i = 1; i <= K; i++) {
        reverse(reversed.begin() + A1, reversed.begin() + A2);
        reverse(reversed.begin() + B1, reversed.begin() + B2);
        if (original == reversed) {
            cnt = i;
            break;
        }
    }
    if (cnt != 0) {
        K %= cnt;
        while (K--) {
            reverse(reversed.begin() + A1, reversed.begin() + A2);
            reverse(reversed.begin() + B1, reversed.begin() + B2);
        }
    }
    for (int i = 1; i <= N; i++)
        fout << reversed[i] << '\n';

    return 0;
}