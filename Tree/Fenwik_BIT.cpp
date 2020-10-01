#include<bits/stdc++.h>

#define ll long long
#define fo(i,n) for(i = 0;i < n;i++)
using namespace std;

#define MAXN 200005
ll n;
ll arr[MAXN];
ll BIT[MAXN];

ll getSumTill(ll ind){
    ll ret = 0;
    ind++;
    while(ind > 0){
        ret += BIT[ind];
        ind -= ind & (-ind);
    }
    return ret;
}

ll querry(ll a,ll b){
    return getSumTill(b) - getSumTill(a-1) ;
}

void update(ll ind,ll val){
    ++ind;
    //ll diff = val - BIT[ind];

    while(ind <= n){
        BIT[ind] += val;
        ind += ind & (-ind);
    }
}
void constructBIT(){
    ll i,j;
    fo(i,n+1)BIT[i] = 0;
    fo(i,n)update(i,arr[i]);
}

int main(){
    cin>>n;
    ll i,j;
    fo(i,n)cin>>arr[i]; 
    
    constructBIT();

    while(1){
        ll type,a,b;

        //Querries are zero based indexed
        cin>>type>>a>>b;
        if(type == 1){
            //Update the value
            update(a,b - arr[a]);
            arr[a] = b;
        }else if(type == 2){
            //Range sum
            cout<<querry(a,b)<<endl;
        }else if(type == 3){
            //Range sum
            cout<<getSumTill(a)<<endl;
        }else{
            cout<<"Invalid type of querry !\n";
        }
    }
    return 0;
}
