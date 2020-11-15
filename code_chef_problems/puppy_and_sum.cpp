#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, d;
    cin>>d>>n;
    int ans = n;
    for (int i = 1; i <= d; i++) {
        ans = ans*(ans + 1) / 2;
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}