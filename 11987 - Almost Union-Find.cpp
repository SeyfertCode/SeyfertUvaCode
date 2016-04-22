#include<bits/stdc++.h>
using namespace std;

vector<int>v(300000);
vector<int>s(300000);
vector<int>c(300000);

int find(int a){
	return a==v[a]?a:v[a]=find(v[a]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
	s[b] += s[a];
	c[b] += c[a];
}
int main(){
	int n,m, x, a, b;
	while(cin>>n>>m){
		for(int i = 1;i<=n;++i){
			v[i] = i+n;
			v[i+n] = i+n;
			s[i+n] = i;
			c[i+n] = 1;
		}
		while(m--){
			cin>>x;
			if(x==1){
				cin>>a>>b;
				a = find(a);
				b = find(b);
				if(a!=b)Union(a,b);
			}else if(x==2){
				cin>>a>>b;
				int x = find(a);
				int y =  find(b);
				if(a!=b){
					v[a] = y;  
                   	s[y] += a;  
                   	s[x] -= a;
					
                   	c[y] ++;  
                   	c[x] --;	
				}
			}else{
				cin>>x;
				x = find(x);
				cout<<c[x]<<" "<<s[x]<<endl;	
			}
		}
	}
}
