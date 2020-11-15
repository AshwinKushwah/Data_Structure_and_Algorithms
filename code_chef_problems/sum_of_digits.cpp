#include<iostream>
using namespace std;
int sum_of_digit(int n){
    int sum=0;
    int rem;
    while(n>0){
        rem=n%10;
        sum=sum+rem;
        n=n/10;        
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int digit;
        cin>>digit;
        cout<<sum_of_digit(digit)<<endl;
    }
    return 0;
}