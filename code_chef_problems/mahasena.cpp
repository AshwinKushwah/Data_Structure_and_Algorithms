#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int even=0,odd=0;
    int i=0;
    while(i<n){
        int weapon;
        cin>>weapon;
        weapon%2==0?even++:odd++;
        i++;
    }
    even>odd?cout<<"READY FOR BATTLE":cout<<"NOT READY"<<endl;
    return 0;
}