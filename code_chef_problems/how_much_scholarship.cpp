#include<iostream>
using namespace std;
int main(){
    int rank;
    cin>>rank;
    if(rank>=1 && rank<=50){
        cout<<"100"<<endl;
    }
    else if(rank>=51 && rank<=100){
        cout<<"50"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }

    return 0;
}