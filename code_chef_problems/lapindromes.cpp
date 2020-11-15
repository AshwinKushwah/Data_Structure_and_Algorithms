#include<iostream>
using namespace std;
void check(string s){
    int n=s.size(), mid=n/2;
        int A[26]={0};
        bool overlap=true;
        for(int j=0;j<mid;j++){
            int x=s.at(j)-'a';
            A[x]++;
        }
        if(n%2!=0){
            mid+=1;
        }
        for(int j=mid;j<n;j++){
            int x=s.at(j)-'a';
            A[x]--;
        }
        for(int j=0;j<26;j++){
            if(A[j]!=0){
                overlap=false;
                break;
            }
        }
        if(overlap){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        check(s);
        
    }
    return 0;
}