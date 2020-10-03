/*Made by Shivam Solanki*/
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define ll long long int
#define endl '\n'
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<pii> vp;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> sii;
typedef set<ll> sll;
typedef queue<int> qii;
typedef priority_queue<int> pq;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll,ll> umll;
#define all(x) x.begin(),x.end()
#define rep(i,k,n) for (int i = k; i < n; ++i) 
#define repr(i,k,n) for (int i = n; i>=k; --i)
#define repll(i,k,n) for (ll i = k; i < n; ++i) 
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 1e9+5;
const int MOD = 1e9+7;
double pi = 2 * acos(0.0); 

//Question Link: https://codeforces.com/contest/887/problem/C

vi cube(25);
vvi sides{
    {1,3,5,7,9,11,24,22},
    {2,4,6,8,10,12,23,21},
    {13,14,5,6,17,18,21,22},
    {15,16,7,8,19,20,23,24},
    {1,2,18,20,12,11,15,13},
    {3,4,17,19,10,9,16,14}    
};

bool check_cube(){
    if(
        (cube[1]==cube[2] and cube[3]==cube[4] and cube[1]==cube[3])
    and (cube[13]==cube[14] and cube[15]==cube[16] and cube[13]==cube[15])
    and (cube[9]==cube[10] and cube[11]==cube[12] and cube[9]==cube[11])
    and (cube[5]==cube[6] and cube[7]==cube[8] and cube[5]==cube[8])
    and (cube[17]==cube[18] and cube[19]==cube[20] and cube[17]==cube[20])
    and (cube[21]==cube[22] and cube[23]==cube[24] and cube[21]==cube[23])
    ) return 1;    
    return 0;
}

void right_shift(vi &side){
    int x=cube[side[0]],y=cube[side[1]];
    for(int i=2;i<8;i+=2)
        swap(cube[side[(i)%8]],x),swap(cube[side[(i+1)%8]],y);
    cube[side[0]]=x,cube[side[1]]=y;
}

void left_shift(vi &side){
    int x=cube[side[0]],y=cube[side[1]];
    for(int i=8;i>=2;i-=2)
        swap(cube[side[(i)%8]],x),swap(cube[side[(i+1)%8]],y);
    cube[side[0]]=x,cube[side[1]]=y ;
}

void solve(){
    rep(i,1,25) cin>>cube[i];
    rep(i,0,6){
        left_shift(sides[i]);
        if(check_cube()){
            cout<<"YES\n";
            return;
        }
        right_shift(sides[i]);
        right_shift(sides[i]);        
        if(check_cube()){
            cout<<"YES\n";
            return;
        }
        left_shift(sides[i]);
    }
    cout<<"NO\n";
}

int main(){ 
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    fastio;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}
