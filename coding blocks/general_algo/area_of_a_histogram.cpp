#include<iostream>
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
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
#define mod 10000000007
#define pb push_back

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef long long ll;


int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
int solve(vector<int> A){
	stack<int> stk;
	int area = -1;
	int max_area = -1;
	int i=0;
	for(i=0;i<A.size();){
		if(stk.empty() || A[stk.top()]<=A[i]){
			stk.push(i++);
		}
		else{
			int top = stk.top();
			stk.pop();
			if(stk.empty()){
				area = A[top] * i;
				max_area = max(max_area,area);
			}
			else{
				area = A[top] * (i-stk.top()-1);
				max_area = max(max_area,area);
			}
		}
	}
	while(!stk.empty()){
		int top = stk.top();
		stk.pop();
		if(stk.empty()){
			area = A[top] * i;
			max_area = max(max_area,area);
		}
		else{
			area = A[top] * (i-stk.top()-1);
			max_area = max(max_area,area);
		}
	}
	return max_area;
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   	int input;
   	vector<int> A;
   	while(cin>>input){
   		A.pb(input);
   	}
   	cout<<solve(A)<<endl;
	return 0;
}
