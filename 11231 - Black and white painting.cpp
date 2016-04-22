//Laxus-Seyfert
#include<bits/stdc++.h>

#define MAX 100
using namespace std;

int main(){
   int b,h,flag,x;
   int init1 = 8,init2=9;
   while(cin>>b>>h>>flag){
      if(b==0&&h==0&&flag==0)break;
      int suma  = 0;
      for(int i=0;i<b-7;i++){
         if(flag){
            x = h-init1;
            if(x>=0)suma+=(x/2)+1;
            flag = 0;
         }else{
            x = (h-init2);
            if(x>=0)suma+=(x/2)+1;
            
            flag = 1;   
         }   
      }   
      cout<<suma<<endl;
   }
   return 0;
}
/***********************************************************/
