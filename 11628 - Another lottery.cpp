//LAxus-Seyfert
#include<bits/stdc++.h>

#define MAX 100

using namespace std;
typedef unsigned long long ull;
ull e(ull a, ull b)
{
   if(b==0)return a;
   return e(b,a%b);
}

int main(){
   int j,r;
   while(cin>>j>>r){
      if(j==0&&r==0)break;
      vector< vector<int> >v(j,vector<int>(r));
      vector<int>sumas (r);
      for(int i=0;i<j;i++){
         
         for(int k=0;k<r;k++){
            cin>>v[i][k];
            sumas[k] +=v[i][k];
         }   
      }
       //buscamos la priemra distinta de cero;
      int p = r-1;
      while(sumas[p]==0)p--;      
      for(int i=0;i<j;i++){
         if(v[i][p] ==0){
            cout<<"0 / 1"<<endl;   
         }else{
            ull mcd = e(v[i][p],sumas[p]);
            cout<<v[i][p]/mcd<<" / "<<sumas[p]/mcd<<endl;      
         }         
      }
        
   }
   return 0;
}
/***********************************************************/
