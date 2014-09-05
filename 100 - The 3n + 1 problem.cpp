//LAXUS-Seyfert
#include<iostream>

using namespace std;

int main()
{
	unsigned long long a,b,max,i,n,lon, aux;
	while(cin>>a>>b){
        cout<<a<<" "<<b<<" ";
        if(a>b)aux=a,a=b,b=aux;   
        max = 0;
        for(i = a;i<=b;i++){
            n = i;
            lon = 1;
            while(n!=1){
               n = (n&1)?3*n+1:n/2; 
               lon++;  
            } 
            if(max<lon)max=lon;       
        }
        cout<<max<<endl;     
    }
	return 0;
}
