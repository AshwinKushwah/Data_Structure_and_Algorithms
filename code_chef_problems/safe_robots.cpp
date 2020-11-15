#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int i,j,l,a,b,f=0;
	    string s;
	    cin>>s>>a>>b;
	    l=s.length();
	    int dot=count(s.begin(),s.end(),'.');
	    for(i=s.find('A')+a,j=s.find('B')-b;i<l,j>=0,dot>0,i<=j;i+=a,j-=b){
	        if(i!=j){
	            s[i]='0';
	            s[j]='0';
	            dot-=2;
	        }
	        else{
	            f=1;
	            break;
	        }
	    }
	    if(f==0){
	        cout<<"safe"<<endl;
        }
	    else{
	        cout<<"unsafe"<<endl;
        }
	}
	return 0;
}