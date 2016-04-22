#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,q,x,c=0,r;
	while(cin>>n){
		if(n==0)break;
		set<int>ms;
		set<int>::iterator ant,it,pos;
		vector<int>v(n);
		scanf("%d",&v[0]);
		for(int i=1;i<n;++i){
			scanf("%d",&v[i]);
			for(int j=0;j<i;++j)ms.insert(v[i]+v[j]);
		}
		scanf("%d",&q);
		printf("Case %d:\n",++c);
		while(q--){
			scanf("%d",&x);
			it = ms.lower_bound(x);
			r = *it;
			if(it!=ms.begin()){
				--it;
				ant=it;
				if(abs(x - *ant) < abs(r-x)) r = *ant;	
				it++;
			}
			if(it!=ms.end()){
				++it;
				pos=it;
				if( abs(*pos - x) < abs(r-x))r = *pos;
				it++;
			}
				
			printf("Closest sum to %d is %d.\n",x,r);
		}
	}
   return 0;
}

