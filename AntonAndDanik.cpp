#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;
    if (s.length() == n)
    {

        int anton = count(s.begin(), s.end(), 'A');
        int danik = count(s.begin(), s.end(), 'D');

        if (anton > danik)
        {
            cout << "Anton" << '\n';
        }
        else if (danik > anton)
        {
            cout << "Danik" << '\n';
        }
        else if (anton == danik || danik == anton)
        {
            cout << "Friendship" << '\n';
        }
    }
    else if (s.length() > n)
    {
        cout << "Invalid number of inputs" << '\n';
    }
    else if (s.length() < n)
    {
        cout << "Invalid number of inputs" << '\n';
    }
}