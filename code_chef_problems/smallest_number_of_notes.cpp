#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
    int A[6]={100,50,10,5,2,1};
	int n;
	cin>>n;
	int count=0;
	for(int i=0;i<6;i++){
        if(n>=A[i]){
            count=count+n/A[i];
        }
	        n=n%A[i];
	        if(n==0){
	        break;
        }
	}
	cout<<count<<endl;
	}
	return 0;
}