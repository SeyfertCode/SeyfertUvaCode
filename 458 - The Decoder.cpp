//BITECODE-ALBERT
#include<iostream>
#include<vector>
/********************************************************************************/
using namespace std;
int main()
{
   string s;
   while(cin>>s){
      
      int lon=s.length();
      vector<char> aux(lon);
      for(int i=0;i<lon;i++)aux[i]+=s[i]-7;   
      for(int i=0;i<lon;i++)cout<<aux[i];
      cout<<endl;
   }
   
   return 0;
}
/********************************************************************************/
