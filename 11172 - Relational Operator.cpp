/*LAXUS-SEYFERT*/
#include<iostream>

using namespace std;

int main()
{
	int a, b,N;
	cin>>N;
    while(N--){
        cin>>a>>b;
        if(a==b)cout<<"="<<endl;    
        else if(a>b)cout<<">"<<endl;
        else cout<<"<"<<endl;
    }
	return 0;
}
