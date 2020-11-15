#include <iostream>
using namespace std;
int main()
{
    int T; 
    cin>>T;
    while(T--)
    {
        string up,bottom; 
        cin>>up>>bottom;
        int A[3]={0};  // b count
        for(int i=0;i<3;i++)  // 'b' present  or not
        {
            if(up[i]=='b' || bottom[i]=='b')
                A[i]=1;
        }
        int b_count=0;
        for(int i=0;i<3;i++){
            if(A[i]==1)
                b_count++;
        }
        if(b_count<=1)
            cout<<"no"<<endl;
        else if(b_count==2)
        {
            int index_of_no_b=0;
            for(int i=0;i<3;i++)
            {
                if(A[i]==0)
                    index_of_no_b=i;
            }
            if(up[index_of_no_b]=='o' || bottom[index_of_no_b]=='o'){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
        else if(b_count==3)
        {
            int o_count=0;
            for(int i=0;i<3;i++)
            {
                if(up[i]=='o' || bottom[i]=='o')
                    o_count++;
            }
            if(o_count==0){
                cout<<"no"<<endl;
            }
            else{
                cout<<"yes"<<endl;
            }
        }
    }
}
