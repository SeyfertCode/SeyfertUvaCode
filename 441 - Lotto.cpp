#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N;
	bool flag=false;
	while(cin>>N){
		if(N==0)break;
		vector<int>v(N);
		vector<int>p(N);
		if(flag)cout<<endl;
		for(int i = 0; i<N;++i){
			cin>>v[i];
			if(i>5)p[i]=1;
		}
		do{
			int c = 0;
			for(int i = 0; i<N;++i){
				if(p[i]==0){
					cout<<v[i];
					if(c<5)cout<<" ";
					c++;	
				}
			}
			cout<<endl;
		}while(next_permutation(p.begin(),p.end()));
		flag = true;
	}
	return 0;
}
