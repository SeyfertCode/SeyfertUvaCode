//LAxus-Seyfert
#include<bits/stdc++.h>
/********************************************************************************/
using namespace std;
typedef unsigned long long ull;
bool isPrime(ull n){
   if(n==1)return false;
   if(n==2)return true;
   if(n%2==0)return false;
   //if(n%6!=1&&n%6!=5)return false;
   for(ull i = 3; i*i<=n;i+=2){
      if(n%i==0)return false;      
   }      
   return true;
}
/********************************************************************************/
int main(){
   int N;
   cin>>N;
   for(int i=1;i<=N;i++){
      string s;
      cin>>s;
      cout<<"Case "<<i<<": ";
      map<char,int>m;
      map<char,int>::iterator it;
      for(int j=0;j<s.size();j++)m[s[j]]++;
      
      bool empty=true;
      for(it=m.begin();it!=m.end();it++){
         if(isPrime(it->second))cout<<(it->first),empty=false;   
      }   
      if(empty)cout<<"empty";
      
      cout<<endl;
   }
   return 0;
}
/********************************************************************************/
