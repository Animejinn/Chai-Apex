#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    int n;
    cin >> n;
    int w;
    cin >> w;

    int total = 0;
    for (int i = 1; i <= w; i++)
    {
        total += k * i;
    }

    if (total > n)
    {
        cout << total - n << '\n';
    }
    else if (total <= n)
    {
        cout<<"0"<<'\n';
    }
}