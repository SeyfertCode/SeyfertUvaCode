#include<iostream>
#include<vector>
using namespace std;

int main(){
	int c = 0;
	int x;
	while(cin>>x){
		if(x<0)break;
		c++;
		cout<<"Case "<<c<<":"<<endl;
		vector<int>v(12);
		vector<int>r(12);	
		for(int i = 0; i<12;++i)cin>>v[i];
		for(int i = 0; i<12;++i)cin>>r[i];
		for(int i = 0; i<12;++i){
			if(x>=r[i]){
				cout<<"No problem! :D"<<endl;
				x -= r[i];
			}else{
				cout<<"No problem. :("<<endl;
			}
			x += v[i];
		}
	}
}
