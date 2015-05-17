/*
Need to implement a 2d fenwick tree


*/

/*


*/
#include<bits/stdc++.h>
using namespace std;
struct Fewnwick2d {
	int tree[1028][1028];
	int s;
	void clear(int s) {
		for ( int i=1; i <=s; i++) 
			for ( int j=1; j<=s; j++)
				tree[i][j]=0;
		this ->s=s;		
	}

	void update(int x, int y, int value) {
		for (int i=x; i<=s; i+= (i& -i) )
			for (int j=y; j <=s; ( j& -j))
				tree[i][j] += value;
	}
	int get(int x,int y) {
		int sum = 0;
		for (int i =x ; i ; i -= (i & -i))
			for ( int j=y; j ; j -= ( j & -j))
				sum += tree[i][j];
		return sum;
	}

	int getValue( int x1, int y1, int x2,int y2) {
		return get(x2,y2) -get(x2,y1-1)-get(x1-1,y2)+get(x1-1,y1-1);
	}

};


int main() {
	int cmd;
	struct Fewnwick2d T;
	while (cin >> cmd, cmd !=3) {
		switch(cmd) {

			case 0:	int n;
					cin >> n;
					T.clear(n);
				break;
			case 1:	int x,y,a;
					cin >>x>>y>>a;
					x++; y++;
					T.update(x,y,a);
					break;
			case 2:	int l,b,r,t;
					cin >> l >>b >>r >>t;
					l++;b++;r++;t++;
					cout << T.getValue(l,b,r,t) << endl;
				break;
			
		}
	}
}
