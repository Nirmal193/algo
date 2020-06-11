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

int lcs(string A,string B){
	int m = A.length();
	int n = B.length();
	int dp[m+1][n+1] = {0};
	for(int i = 0;i<=m;i++)
		dp[i][0] = 0;
	for(int i=0;i<=n;i++)
		dp[0][i] = 0;
	for(int i=1;i<=m ;i++){
		for(int j =i;j<=n;j++){
			if(A[i-1] == B[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else{
				dp[i][j] = MAX(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[m][n];
}
int main(){
  string A,B;
  cin>>A>>B;
  cout<<lcs(A,B)<<endl;
  return 0;
}
