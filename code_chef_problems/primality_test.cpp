#include <iostream>
using namespace std;

int main() {
    int t=0;
    cin>>t;
    while(t--){
        int n=0,flag=0;
        cin>>n;
        for(int i=2;i<=n;i++){
            if(n%i==0){
                flag++;
            }
            
        }
        if(flag<=1 && n!=1){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
	return 0;
}
