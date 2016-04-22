//Laxus-Seyfert
#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    int i=0;
    while(cin>>N){
        if(N<0)break;
        i++;
        cout<<"Case "<<i<<": ";
        cout<<ceil(log(N)/log(2))<<endl;    
    }
	return 0;
}
