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
int maximum_sum(vector<int> A,int B,int C,int D){
	int len = A.size();
	int dp[3][len];
	memset(dp, 0, sizeof(dp[0][0]) * 3 * len);
	dp[0][0] = A[0]*B;
	dp[1][0] = A[0]*B+A[0]*C;
	dp[2][0] = A[0]*B+A[0]*C+A[0]*D;
	for(int i=1;i<len;i++){
		dp[0][i] = MAX(dp[0][i-1],A[i]*B);
		dp[1][i] = MAX(dp[1][i-1],dp[0][i]+A[i]*C);
		dp[2][i] = MAX(dp[2][i-1],dp[1][i]+A[i]*D);
	}
	for(int i=0;i<len;i++){
		cout<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<endl;
	}
	return dp[2][len-1];
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int B,C,D;
    cin>>B>>C>>D;
    int input;
    vector<int> A;
    while(cin>>input)
    	A.pb(input);
    cout<<maximum_sum(A,B,C,D)<<endl;
	return 0;
}
