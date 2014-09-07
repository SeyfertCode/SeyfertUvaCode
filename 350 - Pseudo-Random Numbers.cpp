//LAXUS-Seyfert
#include<iostream>
/********************************************************************************/
using namespace std;
typedef unsigned long long ull;
/********************************************************************************/
int main()
{
   ull z,i,m,seed;
   ull cases=0;
   while(cin>>z>>i>>m>>seed){
      if(z==0&&i==0&&m==0&&seed==0)break;
      cases++;
      ull cont = 1;
      ull primera= (seed*z+i)%m;
      if(primera!=seed){
         ull aux = (primera*z+i)%m;
         while(aux!=primera){
            cont++;
            aux = (aux*z+i)%m;   
         }    
      } 
      cout<<"Case "<<cases<<": "<<cont<<endl;
   }
    return 0;
}
/********************************************************************************/
