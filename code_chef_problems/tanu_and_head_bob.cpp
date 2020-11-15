#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
        int desi=0,videsi=0;
		string s;
		cin>>n>>s;
		for(int i=0;i<n;i++){
			if (s.at(i)=='I'){
				desi++;	
            }
			if (s.at(i)=='Y'){
				videsi++;
            }
		}
		if (desi==0 && videsi== 0){
			cout<<"NOT SURE"<<endl;
        }
		if (desi==0 && videsi!=0){
			cout<<"NOT INDIAN"<<endl;
        }
		if(desi!=0 && videsi==0){
			cout<<"INDIAN"<<endl;
        }
	}
}