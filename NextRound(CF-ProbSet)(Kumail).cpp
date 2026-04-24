#include<iostream>

using namespace std;

int main()
{
    int k = 0, n = 0;
    int p = 0;
    int a[100];
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int threshold = a[k - 1];

    for(int i = 0; i < n; i++)
    {
        if(a[i] >= threshold && a[i] > 0)
        {
            p++;
        }
    }
    
    cout << p;
    
    return 0;
}