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
const int maxn=100009;
vector<int>adj[maxn];
int dp[maxn][2];
int ans=0;
void dfs(int u,int p,vector<int>& A)
{
  dp[u][0]=dp[u][1]=A[u-1];
  for(int v:adj[u])
  {
    if(v==p)continue;
    dfs(v,u,A);
    dp[u][0]=max(dp[u][0],dp[v][0]); //maximum in subtree of u
    dp[u][1]=min(dp[u][1],dp[v][1]); // minimum in subtree of u
    ans=max(ans,abs(A[u-1]-dp[v][0]));
    ans=max(ans,abs(A[u-1]-dp[v][1]));
  }
}
int solve(vector<int> iNums){
	int nums[iNums.size() + 2];
    int n = 1;
    for (int x : iNums) if (x > 0) nums[n++] = x;
    nums[0] = nums[n++] = 1;


    int dp[n][n] = {};
    for (int k = 2; k < n; ++k) {
        for (int l = 0; l < n - k; ++l){
            int r = l + k;
            for (int i = l + 1; i < r; ++i)
                dp[l][r] = max(dp[l][r],
                     nums[l] * nums[i] * nums[r] + dp[l][i] + dp[i][r]);
        }

        }

    return dp[0][n - 1];
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
