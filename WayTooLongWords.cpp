#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    while(n--){
        string s;
        cin>>s;

        int length=s.length();

        if(length>10){
            cout<<s.front()<<length-2<<s.back()<<'\n';
        }else{
            cout<<s<<'\n';
        }
    }

}