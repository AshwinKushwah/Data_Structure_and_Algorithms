#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0,i;
    for(i=n-1;i>=0;i--){
        if(s[i]=='1'){
            count++;
            break;
        }
    }
    cout<<n-i-1<<endl;
    return 0;
}