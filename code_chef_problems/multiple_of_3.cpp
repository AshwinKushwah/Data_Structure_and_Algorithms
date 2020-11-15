// let k=5 of the number (Length of the number)
// number will be 35862 
// Way to geneate = 3 + 5 +mod(3+5) + mod(3+5+8) + mod(3+5+8+6) and so on
// 246248
// to find the next digit, we need to the sum mod 10
// we are doubling and adding
// next digit = prev dgit*2%10

// 2 3 5 0 0 0 0 0 0 0
// 1 2 3 6 2 4 8 6 2 4 8 6 2 4 8 6 2 4 8 6 2 4 8 6
// 8 3 1 2 4 8 6 2 4 8 6 2 4 8 6 2 4 8 6
// 3 4 7 4 8 6 2 4 8 6 2 4 8 6 2 4

// if 0 or 5, then rest of the digits 0
// else 2 4 8 6 2 4 8 6 repeating pattern


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll k;
		int d0,d1;
		cin>>k>>d0>>d1;
		int s = d0+d1;
		int c = (2*s%10+4*s%10+8*s%10+6*s%10);
		ll num_cycles = (k-3)/4;
		ll total = 0;
		if(k==2){
			total = s;
		}else {
			total = s+(s%10)+(c*1ll * num_cycles);
			int left_over = (k-3)-(num_cycles*4);
			int p =2;
			for(int i =1;i<= left_over;i++){
				total+=((p*s)%10);
				p=(p*2)%10;
			}
		}
		if((total%3)==0) {
            cout<<"YES"<<endl;
        }
		else{
            cout<<"NO"<<endl;
        }

	}



}