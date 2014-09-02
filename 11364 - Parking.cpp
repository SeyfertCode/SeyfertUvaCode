//LAXUS-Seyfert
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	while(N--){
		int k;
		cin>>k;
		vector<int>v(k);
		cin>>v[0];
		int max = v[0], min= v[0];
		for(int i = 1;i<k;++i){
			cin>>v[i];
			if(v[i]>max)max=v[i];
			if(v[i]<min)min=v[i];	
		}
		cout<<2*(max-min)<<endl;
	}
}
