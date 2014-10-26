#include<cstdio>
#include<cmath>

int main(){
	int n;
	scanf("%d",&n);
	double l,d;
	while(n--){
		scanf("%lf %lf",&d,&l);
		l/=2;d/=2;
		printf("%.3lf\n", sqrt(l*l-d*d)*l*2*acos(0.0));
	
	}
}
