#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("breedflip.out");
    ifstream fin("breedflip.in");
    int N;
    string A, B;
    fin >> N >> A >> B;
    int cnt = 0;
    for (int i = 0; i < N; ) {
        if (A[i] == B[i])
            i++;
        else {
            while (i < N && A[i] != B[i])
                i++;
            cnt++;
        }
    }
    fout << cnt << '\n';

    return 0;
}