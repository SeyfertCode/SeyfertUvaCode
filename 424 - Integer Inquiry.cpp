//LAXUS-SEYFERT
#include<iostream>
#include<algorithm>
using namespace std;
string suma(string , string);
int main()
{
   string s1,s2;
   cin>>s1;
   while(cin>>s2){
      if(s2=="0")break;
      s1 = suma(s1,s2);
   }
   cout<<s1<<endl;
   return 0;
}
/********************************************************************************/
string suma(string a, string b)
{
   string sum="";
   int i = a.size()-1, j = b.size()-1, carry=0, s=0;
   while(i>=0&&j>=0){
      s = carry + a[i]+b[j]-96;
      carry= s/10;
      sum += (s%10)+48;   
      i--;j--;
   }
   while(i>=0){
      s = carry + a[i] - 48;
      carry= s/10;
      sum += (s%10)+48;   
      i--;
   }
   while(j>=0){
      s = carry + b[j] - 48;
      carry= s/10;
      sum += (s%10)+48;
      j--;    
   }  
   while(carry>0){
      sum += carry%10 +48;
      carry/=10;   
   }
   reverse(sum.begin(),sum.end());
   return sum;
}
/********************************************************************************/
