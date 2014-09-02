//LAXUS-Seyfert
#include<iostream>

using namespace std;
typedef unsigned long long int ull;

ull digit(ull N);
int main()
{
	ull N;
	while(cin>>N){
        if(N==0)break;
        cout<<digit(N)<<endl;    
    }
	//system("pause");
	return 0;
}
ull digit(ull N){
    if(N<10)return N;
    ull aux = 0;
    while(N>0){
        aux += N%10;
        N/=10;        
    }
    return digit(aux);    
}
