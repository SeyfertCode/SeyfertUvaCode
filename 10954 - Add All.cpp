#include<stdio.h>
#include<queue>
using namespace std;
int main(){
	int N;
	while(scanf("%d",&N)==1){
		if(N==0)break;
		int costo = 0, i,aux,prev;
		priority_queue<int>pq;
		for(i = 0; i<N;++i)scanf("%d",&aux),pq.push(-aux);
		for(int i = 0; i<N-1;++i){
			prev = pq.top();pq.pop();
			prev += pq.top();pq.pop();
			costo +=prev;
			pq.push(prev);
		}
		printf("%d\n",-costo);
	}
	return 0;
}
