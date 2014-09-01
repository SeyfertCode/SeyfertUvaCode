//LAXUS-Seyfert
#include<iostream>
using namespace std;
int main()
{
   int N;
   cin>>N;
   for(int i=0;i<N;++i){
      int a,b,c,mayor,menor;
      cin>>a>>b>>c;
      cout<<"Case "<<i+1<<": ";
      mayor = a, menor = a;
		if(b>mayor)mayor = b;
		if(c>mayor)mayor = c;
		if(b<menor)menor = b;
		if(c<menor)menor = c;
		cout<<a+b+c-mayor-menor<<endl;   
   }
   return 0;
}
