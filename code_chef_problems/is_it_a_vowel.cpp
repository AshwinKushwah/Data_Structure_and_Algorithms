#include<iostream>
using namespace std;
int main()
{
    char ch;
    cin>>ch;
    int x=int(ch);
    if(x>=97 && x<=123){
        x=x-32;
    }
    if(char(x)=='A' || char(x)=='E' || char(x)=='I' || char(x)=='O' || char(x)=='U'){
        cout<<"Vowel"<<endl;
    }
    else{
        cout<<"Consonant"<<endl;
    }
    
    return 0;
}