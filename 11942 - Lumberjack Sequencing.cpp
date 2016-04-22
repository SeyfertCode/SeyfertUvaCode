//Laxus-Seyfert
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a1,a2;
	bool cre,dec;
	cin>>n;
	cout<<"Lumberjacks:"<<endl;
	while(n--){
		cre=false, dec=false;
		cin>>a1;
		for(int i =1;i<10;++i){
			cin>>a2;
			if(a2>a1)cre=true;
			else if(a2<a1)dec=true;
			a1=a2;
		}
		(cre&&dec)?cout<<"Unordered"<<endl:cout<<"Ordered"<<endl;
	}
	return 0;
}

