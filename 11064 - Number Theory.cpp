//Laxus-Seyfert
#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
map<ull,ull> facto(ull);
ull coprimos(ull n,map<ull,ull> &primos);
/********************************************************************************/
int main(){
   ull n;
   while(cin>>n){
      if(n==1){
         cout<<"0"<<endl;
         continue;   
      }
      map<ull,ull> f=facto(n);
      map<ull,ull>::iterator it;
      ull num=1;
      for(it = f.begin(); it!=f.end();it++){
         num *=(it->second + 1);  
      }
      num +=coprimos(n,f);
      cout<<n-num+1<<endl;
   }
    return 0;
}
/********************************************************************************/
map<ull,ull> facto(ull n)
{
   map <ull,ull>p;
   while(n%2==0)p[2]++,n/=2;
   for(ull i=3;i*i<=n;i+=2){
      while(n%i==0)p[i]++,n/=i;      
   }
   if(n!=1)p[n]++;
   return p; 
}
ull coprimos(ull n, map<ull,ull> &primos){
   if(n<=1)return 0;   
      //euler:
      map<ull,ull>::iterator it;
      for(it = primos.begin(); it!=primos.end();it++){
         n/=it->first;
         n*=((it->first)-1);      
      }
      return n;  
}
