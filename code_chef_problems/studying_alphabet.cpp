#include<iostream>
using namespace std;

int main()
{
    string s;
    int n;
    int A[26]={0};
    cin>>s;
    cin>>n;
    for(int i=0;i<s.length();i++){
        char ch=s.at(i);
        int p=int(ch);
        p=p-97;
        A[p]=1;
    }
    for(int i=0;i<n;i++){
        string k;
        cin>>k;
        int count=0;
        for(int j=0;j<k.length();j++){
            char z=k.at(j);
            int h=int(z);
            h=h-97;
            if(A[h]==0){
                count++;
            }
        }
        if(count>0){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}