/* 
   Problem link - https://www.codechef.com/LTIME84B/problems/WWALK
   Solution by - pri1998 (codechef handle)  
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    long long int d1=0,d2=0,d=0;
	    cin>>n;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	        cin>>a[i];
	   
	     for(i=0;i<n;i++)
	        cin>>b[i];
	        
	    for(i=0;i<n;i++)
	    {
	        if(d1==d2 && a[i]==b[i]) 
	        d+=a[i]; //distance for which they walk together with same speed i.e. the weird distance
	        
	        d1+=a[i];
	        d2+=b[i];
	    }
	    
	    cout<<d<<'\n';
	}
	return 0;
}
