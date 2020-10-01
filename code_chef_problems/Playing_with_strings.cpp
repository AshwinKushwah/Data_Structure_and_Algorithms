#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string r;
        cin>>r;
        int countS=0;
        int countR=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                countS++;
            }
            if(r[i]=='1'){
                countR++;
            }
        }
        if(countS==countR){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}