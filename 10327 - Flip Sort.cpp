#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		vector<int>v(n);
		for(int i=0; i<n;++i)cin>>v[i];
		int cont = 0;
		for(int i = 0; i<n;++i){
			for(int j = i+1;j<n;j++){
				if(v[i]>v[j])cont++;
			}
		}
		cout<<"Minimum exchange operations : "<<cont<<endl;
	}
}
