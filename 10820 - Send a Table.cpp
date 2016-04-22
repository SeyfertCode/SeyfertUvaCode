//Laxus-Seyfert
#include<bits/stdc++.h>
/********************************************************************************/
using namespace std;

typedef unsigned long long ull;
/********************************************************************************/
map<int,int>fact_prima(int);
ull euler(ull);
map<ull,ull> facto(ull);
/********************************************************************************/
int main(){
   vector<ull>v(50003);
   v[1] = 1;
   for(ull i=2;i<50002;i++){
      v[i] = v[i-1]+euler(i);   
   }
   ull N;
   while(cin>>N){
      if(N==0)break;
      ull rpta = 2*v[N]-1;

      cout<<rpta<<endl;   
   }
    return 0;
}
/********************************************************************************/
map<int,int>fact_prima(int x){
   map<int,int>res;
   while(x%2==0){x/=2;res[2]++;}
   int c=3;
   while(c<=sqrt(double(x))+1){
      if(x%c==0){res[c]++; x/=c;}
      else c+=2; 
   } 
   if(x>1)res[x]++;
      return res;  
}
/********************************************************************************/

ull euler(ull n){
   if(n<=1)return 0;   
   //euler:
   map <ull,ull>primos = facto(n);
   map<ull,ull>::iterator it;
   for(it = primos.begin(); it!=primos.end();it++){
      n/=it->first;
      n*=((it->first)-1);      
   }
   return n;  
}
/********************************************************************************/
map<ull,ull> facto(ull n){
   map <ull,ull>p;
   while(n%2==0)p[2]++,n/=2;
   for(ull i=3;i*i<=n;i+=2){
      while(n%i==0)p[i]++,n/=i;      
   }
   if(n!=1)p[n]++;
   return p; 
}
