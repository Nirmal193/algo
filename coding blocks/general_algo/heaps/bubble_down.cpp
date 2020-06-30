/*
  This code is for changing an array to a max heap or min heap according to your need
  by bubble down approach really halpfull for heapsorts

  Auther:-Nirmal Kumar Rout(Wizzard)
*/
#include<iostream>
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define pb push_back

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef long long ll;
const int mod = 1e9+7;
int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i + 1); }
int right(int i) { return (2*i + 2); }

int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
int gcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int x1,y1;
	int ans = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return ans;

}
void minheapify(vector<int> &A,int index){
	int l = left(index);
	int r = right(index);
	if(l>= A.size() && r>= A.size())
		return;
	int smallest = 0;
	if(l<A.size() && A[l] < A[index])
		smallest  = l;
	else
		smallest = index;
	if(r<A.size() && A[r] < A[index])
		smallest = r;
	if(smallest != index)
		swap(A[index],A[smallest]);
	else
		return;
	minheapify(A,smallest);
}
void maxheapify(vector<int> &A,int index){
	int l = left(index);
	int r = right(index);
	if(l>= A.size() && r>=A.size())
		return;
	int largest = 0;
	if(l<A.size() && A[l]>A[index])
		largest = l;
	else
		largest = index;
	if(r<A.size() && A[r]>A[index])
		largest = r;
	if(largest!=index)
		swap(A[index],A[largest]);
	else
		return;
	maxheapify(A,largest);
}
int solve(vector<int> A){
	for(int i=A.size();i>=0;i--){
		maxheapify(A,i);
	}
	for(int i : A)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int input;
    vector<int> A;
    while(cin>>input){
    	A.push_back(input);
    }
    cout<<solve(A)<<endl;
	return 0;
}
