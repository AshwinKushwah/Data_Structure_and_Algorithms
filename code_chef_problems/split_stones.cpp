#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b,c,x,y;
	    cin>>a>>b>>c>>x>>y;
	    int m;
	    m=min(a,b);
	    m=min(m,c);
	    if(x<m || y<m)
	        cout<<"NO"<<endl;
	    else if(a+b+c == x+y)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	return 0;
}
