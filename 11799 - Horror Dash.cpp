//LAXUS-Seyfert
#include<stdio.h>

using namespace std;
int main()
{
   int N;
   scanf("%d",&N);
   for(int i=0;i<N;++i){
      int K,x,mayor=0;
      scanf("%d%d",&K,&mayor);
      for(int j=1;j<K;++j){
         scanf("%d",&x);
         if(mayor<x)mayor = x;   
      }   
      printf("Case %d: %d\n",i+1,mayor);
   }
   return 0;
}
/********************************************************************************/
