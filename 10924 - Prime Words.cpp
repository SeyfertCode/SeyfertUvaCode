//BITECODE-ALBERT
#include<iostream>
#include<vector>
/********************************************************************************/
using namespace std;

typedef unsigned long long ull;
bool isPrime(ull n){
   if(n==1)return true;
   if(n==2)return true;
   if(n%2==0)return false;
   //if(n%6!=1&&n%6!=5)return false;
   for(ull i = 3; i*i<=n;i+=2){
      if(n%i==0)return false;      
   }      
   return true;
}
/********************************************************************************/
int main()
{
   string s;
   while(cin>>s){
      int sum=0;
      for(int i=0;i<s.size();i++){
         if(s[i]>='a'&&s[i]<='z')sum+=s[i]-96;
         else sum+=s[i]-38;
      }
      if(isPrime(sum))cout<<"It is a prime word."<<endl;
      else cout<<"It is not a prime word."<<endl;  
   }
   return 0;
}
/********************************************************************************/
