//Laxus-Seyfert
#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    while(N!=0){
        vector<int> v(N);
        for(int i=0;i<N;i++)scanf("%d", &v[i]);
        sort(v.begin(), v.end()); 
        int i=0; 
        for(i=0;i<N;i++){
            printf("%d",v[i]);
            if(i<N-1)printf(" ");
            else printf("\n");
        }
        scanf("%d", &N);
    }
	return 0;
}
/*
  Existe una soluci�n m�s �ptima: creando un vector de dimensi�n 100 (ya que lam�xima edad es 99)
  y cuentas cuantos de cada uno aparecen, para luego mostrarlos, en este caso, quise probar con unos compa�eros
  lo potente que es el "sort" del c++ (en Java sale TLE :P )
*/
