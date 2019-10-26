#include<iostream.h>
#include<iomanip.h>
#include<ctype.h>
 
template<class Type>
class queue
{
private:
   Type size;
   Type start;
   Type end;
   Type *data;
public:
    queue()
    {
      size=20;
      start=end=0;
      data=new Type[size];
    }
 
    queue(Type n)
    {
      size=n;
      start=end=0;
      data=new Type[size];
    }
 
       ~queue()
       {
         delete data;
       }
    void put(Type value)
    {
      if((start+1)size==end)
      {
       cout<<"\n***Queue is full!***\n";
       return ;
       }
       data[start]=value;
       start=(start+1)size;
       cout<<"You have put a data into the queue!\n";
       return;
    }
 
    Type get()
    {
      Type value;
      if(start==end)
      {
        cout<<"\n***Queue is empty!***\n";
        return(0);
      }
      value=data[end];
      end=(end+1)size;
      cout<<"\n Get "<<value<<" from the queue!\n";
      return(value);
    }
 
    void clear()
    {
      start=end;
      cout<<"\n ***Queue is empty!***\n";
    }
 
    void ShowQueue()
    {
       if(start==end)
       {
        cout<<"\n The queue has no data!\n";
        return;
       }
       Type i;
       cout<<"\n The content of queue:\n";
       for(i=end;i!=start;i=((i+1)size))
          cout<<setw(5)<<data[i];
       cout<<"\n\n";
    }
 
};
 
main()
{
  queue<char> ss(5);
  char value = 'a';
  ss.put(value);
  ss.put('b');
  value=ss.get();
  ss.clear();
  ss.ShowQueue();
}
