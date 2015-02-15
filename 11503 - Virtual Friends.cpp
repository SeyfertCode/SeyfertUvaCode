#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int v[200010];
int root[200010];

void Union(int x, int y);
 
int main()
{
    int Case, F;
    cin >> Case;
    while (Case--) {
        cin >> F;
        map<string, int> mm;
        for (int i = 0; i <= 2*F; ++i) {
        	v[i] = i;
        	root[i] = 1;
    	}
 
        string A, B;
        for (int i = 0, j = 1; i < F; ++i) {
            cin >> A >> B;
            if (!mm[A]) mm[A] = j++;
            if (!mm[B]) mm[B] = j++;
            Union(mm[A], mm[B]);
        }
    }
}

int Find(int x)
{
    if (x == v[x])
        return x;
    return v[x] = Find(v[x]);
}
bool sameFather(int x, int y)
{
	return Find(x)==Find(y);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
 
    if (!sameFather(x,y)) {
        v[x] = y;
        root[y] += root[x];
    }
    cout << root[y] << endl;
}
