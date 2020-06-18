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
#define pb push_back	`

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
	int N = A.size();
    unordered_map<int, int> index;
    for (int i = 0; i < N; ++i)
        index[A[i]] = i;

    unordered_map<int, int> longest;
    int ans = 0;
    for (int k = 0; k < N; ++k)
        for (int j = 0; j < k; ++j) {
            if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                int i = index[A[k] - A[j]];
                longest[j * N + k] = longest[i * N + j] + 1;
                ans = max(ans, longest[j * N + k] + 2);
            }
        }

    return (ans >= 3) ? ans : 0;
}
int solve2(vector<int> A){
	 unordered_map<int, int> m;
        int N = A.size(), res = 0;
        int dp[N][N];

        for (int j = 0; j < N; ++j) {
            m[A[j]] = j;
            for (int i = 0; i < j; ++i) {
                int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
                dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
                res = max(res, dp[i][j]);
            }
        }
        for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<dp[i][j]<<"       ";
		cout<<endl;
	}

        return res > 2 ? res : 0;
}
int solve1(vector<int> A){
	unordered_map<int,int> m;
	int len = A.size();
	int dp[len][len];
	int res = 0;
	for(int j=0;j<len;j++){
		m[A[j]] = j;
		for(int i=0;i<j;i++){
			int index = m.find(A[j] - A[i]) ==m.end() ? -1 : m[A[j] -  A[i]];
			dp[i][j] = (A[j]-A[i]<A[i] && index >= 0)?dp[i][j] = dp[index][i]+1 : 2;
			res = max(res,dp[i][j]);
		}
	}
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return res == 2? 0: res;
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   	vector<int> A;
   	int input;
   	while(cin>>input)
   		A.push_back(input);
   	cout<<solve1(A)<<endl;
	return 0;
}
