//LAXUS-Seyfert
#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
   string s;
   while(cin>>s){
      if(s=="#")break;
      string aux = s;
      sort(aux.begin(),aux.end());
      next_permutation(s.begin(),s.end());
      if(s==aux)cout<<"No Successor"<<endl;
      else cout<<s<<endl;   
   }
    return 0;
}
