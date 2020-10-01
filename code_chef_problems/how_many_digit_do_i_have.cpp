#include<iostream>
using namespace std;
void count_digit(int n){
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    switch(count){
        case 1:
        cout<<"1"<<endl;
        break;
        case 2:
        cout<<"2"<<endl;
        break;
        case 3:
        cout<<"3"<<endl;
        break;
        default:
        cout<<"More than 3 digits"<<endl;
        break;
    }
}
int main()
{
    int n;
    cin>>n;
    count_digit(n);
    return 0;
}