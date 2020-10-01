#include<iostream>
using namespace std;
int count_four(int n){
    string my_str=to_string(n);
    int count=0;
    for(int i=0;i<my_str.length();i++){
        if(my_str.at(i)=='4'){
            count++;
        }
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        cout<<count_four(num)<<endl;
    }
    return 0;
}