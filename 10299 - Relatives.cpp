//Laxus-Seyfert
#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
map<ull,ull> facto(ull);

int main(){
   ull n;
   while(cin>>n){
      if(n==0)break;
      if(n<=1){
         cout<<"0"<<endl;
         continue;   
      }
      //euler:
      map <ull,ull>primos = facto(n);
      map<ull,ull>::iterator it;
      for(it = primos.begin(); it!=primos.end();it++){
         n/=it->first;
         n*=((it->first)-1);      
      }
      cout<<n<<endl;
   }
    return 0;
}

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
