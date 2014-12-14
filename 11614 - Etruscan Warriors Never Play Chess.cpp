//Laxus-Seyfert
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	unsigned long long int x;
	while(N--){
        cin>>x;
        double r = sqrt(1+8*x);
        r = (r-1)/2;
        cout<<int(r)<<endl;    
    }
	return 0;
}
