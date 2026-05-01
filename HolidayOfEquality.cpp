#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] >= max)
        {
            max = arr[i];
        }
    }

    int total=0;
    int diff;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < max)
        {
            diff = max - arr[i];
            total+=diff;
        }
    }

    cout <<total<<endl;
}