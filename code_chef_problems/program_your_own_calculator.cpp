#include<iostream>
using namespace std;
int main(){
    double a,b;
    cin>>a>>b;
    char ch;
    cin>>ch;
    switch(ch){
        case '+':
        cout<<a+b<<endl;
        break;
        case '-':
        cout<<a-b<<endl;
        break;
        case '*':
        cout<<a*b<<endl;
        break;
        case '/':
        cout<<fixed<<(a/b)<<endl;
        break;
    }
    return 0;
}