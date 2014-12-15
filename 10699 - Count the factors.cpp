//Laxus-Seyfert
#include<bits/stdc++.h>
using namespace std;

int main(){
   int N;
   while(cin>>N){
      if(N==0)break;
      cout<<N<<" : ";
      int cont_primos=0;
      bool contado=false;
      while(N%2==0){
         if(!contado)contado=true,cont_primos++;
         N>>=1;   
      }
      for(int i=3;i*i<=N;i+=2){
         contado=false;
         while(N%i==0){
            if(!contado)contado=true,cont_primos++;
            N/=i;          
         }   
      }
      if(N>1)cont_primos++;
      cout<<cont_primos<<endl;
   }
    return 0;
}
/********************************************************************************/
