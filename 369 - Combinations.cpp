//LAXUS-Seyfert
#include<iostream>
#include<vector>

using namespace std;

typedef unsigned long long int ulli;
vector<vector<ulli> > v(101,vector<ulli>(101));
void trianguloPascal(){
   v[0][0] = 1;
   v[1][0] = 1;
   v[1][1] = 1;
   for(ulli i=2;i<101;i++)v[i][0]=1,v[i][1]=i,v[i][i]= 1 ;

   for(ulli i=3;i<101;i++){
      for(ulli j = 2;j<i;j++){
         v[i][j] = v[i-1][j-1]+v[i-1][j];   
      }   
   } 
}
int main(){
   int n, k;
   trianguloPascal();
   while(cin>>n>>k){
        if(n==0)break;
      cout<<n<<" things taken "<<k<<" at a time is "<<v[n][k]<<" exactly."<<endl;   
   } 
   return 0;
}
