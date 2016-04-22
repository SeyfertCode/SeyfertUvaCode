//Laxus-Seyfert
#include<bits/stdc++.h>
/********************************************************************************/
using namespace std;
typedef unsigned long long ull;
ull cantDiv(ull N){
   if(N==1)return 1;
   ull i = 1;
   int p=0;
   while(i*i<N){
         if(N%i==0)p++;
         i++;   
         
   } 
   p*=2;
   if(i*i==N)p++;
   return p;
}
/********************************************************************************/
int main(){

   vector<int>v(64725);
   v[0]=1;v[1]=2;
   for(int i = 2;i<64725;i++)v[i] = v[i-1]+cantDiv(v[i-1]);
   vector<int>::iterator low,up;
   int N,a,b;
   scanf("%d ",&N);
   int i;
   for(i=1;i<N+1;i++){
      scanf("%d %d", &a, &b);
      low = lower_bound(v.begin(),v.end(),a);
      up = upper_bound(v.begin(),v.end(),b);  
      cout<<"Case "<<i<<": "<<(int)(up-low)<<endl;
   }
    return 0;
}
/********************************************************************************/

