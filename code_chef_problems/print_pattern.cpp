// WHen n=4
// 1 2 4 7
// 3 5 8 11
// 6 9 12 14
// 10 13 15 16

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int last;
        cin>>n;
        int i,j;
        int A[n][n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==0 && j==0){
                    A[i][j]=1;
                }
                else if(j==0 && i>0){
                    A[i][j]=A[i-1][j+1]+1;
                }
                else if((i+j)<n && j>0){
                    A[i][j]=i+j+A[i][j-1];
                }
                else{
                    if((i+j)==n){
                       last=n-1;
                    }
                    A[i][j]=A[i][j-1]+last;
                    last--;
                }
            }
        }

        // Printing the obtained pattern
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }  
        cout<<endl;
    }
    return 0;
}
