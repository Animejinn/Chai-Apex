// 339A. Helpful Maths

#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;

    vector<int> nStor;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != '+') {
            nStor.push_back(input[i] - '0');
        }
    }

    sort(nStor.begin(), nStor.end());

    for (int i = 0; i < nStor.size(); i++) {
        cout << nStor[i];
        if (i < nStor.size() - 1) {
            cout << "+";
        }
    }
}