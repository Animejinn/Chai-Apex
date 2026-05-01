// 160A. Twins

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int temp;
    int nC;
    cin>>nC;

    vector<int> cVal;
    int cValSum = 0;
    int tCSum = 0; // twin coin sum
    int Cs = 0; 

    for(int i = 0; i < nC; i++)
    {
        cin>>temp;
        cVal.push_back(temp);
        cValSum += cVal[i];
    }

    sort(cVal.begin(), cVal.end(), greater<int>());

    int j = 0;

    while(tCSum <= cValSum/2)
    {
        //cout<<'\n'<<j;
        tCSum += cVal[j];
        //cout<<'\n'<<tCSum<<"  "<<cValSum;
        Cs++;
        //cout<<'\n'<<Cs;
        j++;
    }
    

    cout<<'\n'<<Cs;
}