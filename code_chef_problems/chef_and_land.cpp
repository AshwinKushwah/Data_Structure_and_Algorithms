/*
 Chef lives in Chefland. Chefland can be thought as a two-dimensional grid of dimensions NxM. Some of the cells of the Chefland are prohibited to visit (denoted by '*'). One can never step on such prohibited cells. There is a city at each at each non-prohibited cell (will be denoted by '.' or 'C' (denoting capital city)).

Sadly people in the capital city of Chefland (denoted by 'C') are lazy for their shopping. So they invented a robot for carrying their groceries. They want to feed a command of at max 105 characters to the robot such that if the robot starts from any cell (non-prohibited) of the grid, it should be able to visit the capital city during its walk. Each character of the command will be one of 'U', 'D', 'L', 'R' denoting the movement to go up, down, left and right cell from the current cell (provided it exists and the cell is not prohibited to visit). Otherwise, the robot will just stay at its current cell. The characters of the command will be followed in the order from left to right.

Now, after thinking a lot, citizens of Chefland could not come up such a command to feed to robot. So, they ask your help in it. They have come to know from an oracle that it is guaranteed that such a command exists. 
*/

#include<bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end(); it++)

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

const int mod = 1000000007;
inline void add(int &x, int y){x+=y; if(x>=mod)x-=mod; if(x<0)x+=mod;}
inline int mul(int x, int y){ return ((LL)x * y)%mod;}
int gcd(int a, int b){ if(b)return gcd(b,a%b); return a;}
int power(int a ,int p){int ret = 1; while(p){if(p&1)ret=mul(ret,a); a=mul(a,a); p/=2;}return ret;}
int phi(int n){ int ret=n; int i = 2; 
    if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    for(i=3; i*i<=n; i++)if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    if(n>1)ret-=ret/n;return ret;
}



int main(int argc, char** argv)
{
    string M = "LRDU";
    for(int i =0; i<99999; i++) cout << M[rand() % 4]; cout<<endl;
    return 0;	
}