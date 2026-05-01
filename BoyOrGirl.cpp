#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    set<char> unique(s.begin(), s.end());

    int count = unique.size();

    if (count % 2 == 0 || count == 2)
    {
        cout << "CHAT WITH HER!" << '\n';
    }
    else
    {
        cout << "IGNORE HIM!" << '\n';
    }
}