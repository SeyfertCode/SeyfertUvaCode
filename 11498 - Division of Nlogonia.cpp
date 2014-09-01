//BITECODE-ALBERT
#include<iostream>
using namespace std;
int main()
{

   int N;
   while(cin>>N){
      if(N==0)break;
      int X,Y;
      cin>>X>>Y;
      while(N--){
         int a,b;
         cin>>a>>b;
         a-=X;
         b-=Y;
         if(a==0||b==0)cout<<"divisa"<<endl;
         else if(a>0&&b>0)cout<<"NE"<<endl;   
         else if(a>0&&b<0)cout<<"SE"<<endl;  
         else if(a<0&&b>0)cout<<"NO"<<endl;  
         else if(a<0&&b<0)cout<<"SO"<<endl;  
      }
   }
   return 0;
}
