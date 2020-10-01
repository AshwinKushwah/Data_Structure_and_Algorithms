// Enormous Input Test

// int range - 10^7 - 10^8 (Remember)

#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    int count=0;
    for(int i=0;i<n;i++){
        long long int t;
        cin>>t;
        if(t%k==0){
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}