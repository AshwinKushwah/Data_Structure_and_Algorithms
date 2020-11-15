#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int res = a+b;
        int countMatches=0;
        int j;
        for(int i=res;i>0;i=i/10){
            j=i%10;
            switch(j){
                case 0:
                countMatches+=6;
                break;
                case 1:
                countMatches+=2;
                break;
                case 2:
                countMatches+=5;
                break;
                case 3:
                countMatches+=5;
                break;
                case 4:
                countMatches+=4;
                break;
                case 5:
                countMatches+=5;
                break;
                case 6:
                countMatches+=6;
                break;
                case 7:
                countMatches+=3;
                break;
                case 8:
                countMatches+=7;
                break;
                case 9:
                countMatches+=6;
                break;
            }
        }
        cout<<countMatches<<endl;




    }
    return 0;
}