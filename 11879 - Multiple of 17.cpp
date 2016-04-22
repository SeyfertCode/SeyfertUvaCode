//Laxus-Seyfert
#include<bits/stdc++.h>
/********************************************************************************/
using namespace std;
bool isMulti(string, int, int);
/********************************************************************************/
int main(){
   string s;
   while(cin>>s){
      if(s=="0")break;
      (isMulti(s,10,17))?cout<<"1"<<endl:cout<<"0"<<endl;      
   }
    return 0;
}
/********************************************************************************/
bool isMulti(string s, int n, int m)
{
   int res = 1;
   int mod = 0;
   for(int i= s.size()-1;i>=0;i--){
      mod += ((s[i]-48)*res)%m;
      mod = mod%m;
      res = (res*n)%m;     
   }
   return mod==0?true:false;
}
