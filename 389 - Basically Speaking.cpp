//LAXUS-Seyfert
#include<iostream>
/********************************************************************************/
using namespace std;

typedef unsigned long long ull;
string changeBase(string,int,int);
/********************************************************************************/
int main()
{
   int b,n;
   string num;
   while(cin>>num>>b>>n){
      string resp = changeBase(num,b,n);
      int x = resp.size();
      if(x>7){
         cout<<"  ERROR"<<endl;   
      }else{
         for(int i= 0;i<7-x;i++)cout<<" ";
         for(int i=x-1;i>=0;i--)cout<<resp[i];
         cout<<endl;   
      }
         
   }
   return 0;
}
/********************************************************************************/
string changeBase(string num,int b,int n){
   ull aux = 0;
   ull pow=1;
   for(int i=num.size()-1;i>=0;i--){
      switch(num[i]){
         case 'A':
            num[i] = 58;
            break;
         case 'B':
            num[i] = 59;
            break;
         case 'C':
            num[i] = 60;
            break;
         case 'D':
            num[i] = 61;
            break;
         case 'E':
            num[i] = 62;
            break;
         case 'F':
            num[i] = 63;
            break;   
      }
      aux +=(num[i]-48)*pow;
      pow *=b;   
   }
   string result = "";
   while(aux>0){
      int p = aux%n;
      if(p>=10)result += p + 55;
      else result += p+48;
      aux/=n;    
   }
   if(result == "")return "0";
   return result;
}
/********************************************************************************/
