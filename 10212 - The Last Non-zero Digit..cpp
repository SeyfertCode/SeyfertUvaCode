//Laxus-Seyfert
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll N,M;
   while(cin>>N>>M){
   	ll res=1;
      ll cont2=0,cont5=0;
      for(ll i = N-M +1 ;i<=N;i++){
      	ll aux = i;
         while(aux%5==0)cont5++,aux/=5;
         while(aux%2==0)cont2++,aux/=2;
         aux%=10;
         res*=aux;
         res %=10;      
      }
      if(cont2>=cont5){
         cont2 = cont2 - cont5;
         if(cont2>0){
            cont2%=4;
            if(cont2==0)res*=6;
            else if(cont2==1)res*=2;
            else if(cont2==2)res*=4;
            else res*=8;   
         }   
      }else res*=5;         
      cout<<res%10<<endl;
   }
   return 0;
}
