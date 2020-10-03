/* Problem - Given a string without spaces, the task is to remove duplicates from it.  
    Problem link - https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1
    Solution by - Priyanka Roy Chowdhury
*/

/*Code*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,i; string s;
	cin>>t;
	cin.ignore();
	
	while(t--)
	{
	    getline(cin,s); //Taking a string as input
	    transform(s.begin(), s.end(), s.begin(), ::tolower); //converting the whole string to lower case
	    int f[26]={0};
	    int i;
	    for(i=0;i<s.length();i++)
	    {
	        f[s[i]]+=1;
	    }
	    string res="";
	    for(i=0;i<s.length();i++)
	    {
	        if( f[s[i]])
	        {
                res+=s[i]; f[s[i]]=0; //Take only the first occurence of each char
            }
	    }
        cout<<res<<endl;
	    
	}
	return 0;
} 