/*
	K V K
	solved the problem using dynamic programming problem

	m[0]=0
	m[i,w]=m[i-1.w] if wi >w
	m[i,w]= min(m[i-1,w],m[i-1,w-wi]+v[i])

	solved it using a one dimensional array instead of 2 dimensional array

*/
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

const int wMax =10005;
void knapsack( int weight, int n, int p[], int w[]) {
	int k[wMax];
	fill(k, k+wMax, INT_MAX);

	for (int i=1; i<=weight; i++) {
		for (int j=0; j<n; j++) {
			if (i == w[j]) { // if k is a 2 dimensional matrix this is not needed
			 k[i] = min(k[i],p[j]);
			}else if ( i > w[j] && k[i-w[j]] != INT_MAX) {
				k[i] = min(k[i], p[j] + k[i -w[j]]);
			}
		}
	}
	if (k[weight] != INT_MAX) {
		cout <<"The minimum amount of money in the piggy-bank is "<<k[weight]<<"."<<endl;			
	} else {
	cout <<"This is impossible."<<endl;
	}
}


int main() {

	int t,e,f,n;
	cin >>t;
	while (t-- >0) {
		cin >> e >>f;
		cin >>n;
		int p[n],w[n];
		//p = new int[n];
		//w = new int[n];
		for (int i=0; i<n; i++)
			cin >> p[i] >> w[i];
		knapsack(f-e,n,p,w);
	}
	return 0;
}
