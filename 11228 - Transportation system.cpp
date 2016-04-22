#include<bits/stdc++.h>
#include<utility>

using namespace std;


vector<int>v(1000);
struct Edge{
	int x;
	int y;
	double w;	
};

bool cmp(Edge a, Edge b){
	return a.w<b.w;
}

int find(int a){
	return a==v[a]?a:v[a]=find(v[a]);
}
void Union(int a, int b){
	v[find(a)]=find(b);
}

bool sameFather(int a, int b){
	return find(a)==find(b);
}

double dist(pair<double,double> a, pair<double,double> b){
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));	
}

int main(){
	map<pair<double,double> , int>mm;
	vector<Edge>edges;
	int n;
	cin>>n;
	for(int cas = 0;cas<n;++cas){
		int V, cont=1;
		double distMax;
		cin>>V>>distMax;
		mm.clear();
		edges.clear();
		Edge auxEdge;
		pair<double,double>auxP;
		vector<pair<double,double> >points(V);
		for(int j=0;j<V;++j){
			v[j+1] = j+1;
			cin>>auxP.first>>auxP.second;
			if(!mm[auxP])mm[auxP]=cont++, points[j] = auxP;
		}					
		
		//calculamos todas las distancias O(n^2)
		for(int i = 0;i<V-1;++i){
			for(int j = i+1;j<V;++j){
				auxEdge.x= mm[points[i]];
				auxEdge.y= mm[points[j]];
				auxEdge.w= dist(points[i],points[j]);
				edges.push_back(auxEdge);
			}
		}
		
		//kruskal:
		sort(edges.begin(),edges.end(),cmp);
		double total1 = 0.0;
		double total2 = 0.0;
		int states=1;		
		for(int i = 0;i<edges.size();++i){
			if(!sameFather(edges[i].x,edges[i].y)){
				if(edges[i].w<distMax){
					total1+=edges[i].w;
				}else{
					total2+=edges[i].w;
					states++;
				}
				Union(edges[i].x,edges[i].y);	
			}
		}
		int conv1 = floor(total1);
		int conv2 = floor(total2);
		if(total1-conv1>=0.5)conv1++;
		if(total2-conv2>=0.5)conv2++;
		cout<<"Case #"<<cas+1<<": "<<states<<" "<<conv1<<" "<<conv2<<endl;
		
	}
	
}



