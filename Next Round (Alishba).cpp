#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout<<"enter n and k";
    cin >> n >> k;

    int a[50];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int kthScore = a[k - 1];
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] >= kthScore && a[i] > 0) {
            count++;
        }
    }

    cout << count;

    return 0;
}