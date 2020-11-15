#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int salary;
        cin>>salary;
        double hra=0,da=0,gross=0;
        if(salary<1500){
            hra=0.1*salary;
            da=0.9*salary;
            gross=salary+hra+da;
        }
        else{
            hra=500;
            da=0.98*salary;
            gross=hra+da+salary;
        }
        cout<<fixed<<gross<<endl;
    }
    return 0;
}