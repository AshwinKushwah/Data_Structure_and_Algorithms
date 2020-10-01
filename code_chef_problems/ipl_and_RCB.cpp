#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int points, matches;
        cin>>points>>matches;
        int count=0;
        if(points<=matches){
            cout<<0<<endl;
        }
        else{
            cout<<(points-matches)<<endl;
        }
    }
    return 0;
}