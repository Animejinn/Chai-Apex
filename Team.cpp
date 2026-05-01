#include <iostream>
using namespace std;

int main() {
int n;
cout<<"Enter number of problems!"<<endl;
cin>>n;
int peeps[3];
int count=0;

for(int i=0;i<n;i++){
    cin>>peeps[0];
    cin>>peeps[1];
    cin>>peeps[2];
      
      if(peeps[0]+peeps[1]+peeps[2] > 2){
          count++;
      }
}
cout<<count<<endl;
}