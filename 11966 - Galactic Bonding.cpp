#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
vector<int>v(MAX+10);


int find(int a){
	return v[a]==a? a:find(v[a]);
}
bool parents(int a, int b){
	return find(a)==find(b);	
}
void Union(int a, int b){
	if(!parents(a,b)){
		v[find(a)] = find(b);	
	}
}
int main(){
	int caso;
	cin>>caso;
	int N;
	double D;
	for(int c=0;c<caso;++c){
		cin>>N>>D;
		vector<double>x(N),y(N);
		for(int i = 0;i<N;++i)v[i] = i;
		for(int i = 0;i<N;++i){
			cin>>x[i]>>y[i];
			for(int j = 0;j<i;++j){
				double dist= sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
				if(dist-D<1e-8){
					Union(i,j);	
				}
			}
		}

		set<int>ms;
		for(int i = 0;i<N;++i){
			ms.insert(find(v[i]));
		}
		
		cout<<"Case "<<c+1<<": "<<ms.size()<<endl;

	}
   return 0;
}
