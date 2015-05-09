#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX = 100001; 

#define CLR(p) memset(p,0,sizeof(p))

long long a[MAX],BIT[MAX];
int root[MAX];
void update (int x, long long value, int n) {
	while (x <= n) {
		BIT[x] += value;
		x += (x & -x);
	}
}

long long readsum(int x) {
	long long value=0;
	while (x > 0) {
		value += BIT[x];
		x -= (x & -x); 
	}
	return value;
}

int find(int u) {
	if (u != root[u]) root[u]=find(root[u]);
	return root[u];
}
void modify(int x, int y, int n) {
	int i=find(x);
	while(x <=i && i <= y) {
		if (a[i] != 1) {
			update(i,-a[i],n);
			a[i] = (long long) floor(sqrt((double)a[i]));
			update(i,a[i],n);
			if(a[i] == 1) root[i] = i + 1;
		}
		i = find(i+1);
	}
}

long long getsum (int x, int y) {
	return (readsum(y) - readsum(x-1));
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,q,cs,i,x,t,y;
	for ( cs =1; scanf("%d",&n) == 1; cs++) {
	 	CLR(BIT);
		for (i=1; i <=n; i++) {
			scanf ("%lld",a+i);
			update (i,a[i],n);
			root[i]=i;
		}
		printf("Case #%d:\n",cs);
		scanf("%d",&q);
		while(q--) {
			scanf("%d %d %d",&t,&x,&y);
			if (x > y) swap(x,y);
			if (t)  printf("%lld\n",getsum(x,y));
			else modify(x,y,n);
		}
	    printf("\n");
	}
	return 0;
}
