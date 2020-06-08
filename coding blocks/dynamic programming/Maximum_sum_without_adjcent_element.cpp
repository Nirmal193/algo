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
int max_sum_without_adjcent_element(vector<vector<int>> A){
	int len = A[0].size();
	vector<int> B;
	for(int i=0;i<len;i++){
		B.push_back(MAX(A[0][i],A[1][i]));
	}
	int dp[len];
	memset(dp,0,sizeof(dp[0])*len);
	dp[0] = B[0];
	dp[1] = MAX(B[0],B[1]);
	for(int i=2;i<len;i++){
		dp[i] = MAX(dp[i-1],B[i]+dp[i-2]);
	}
	return dp[len-1];
}
int main(){
 	// freopen("input.txt","r",stdin);
  //   freopen("output.txt","w",stdout);
    int n,m;
    cin>>n;
    int input;
    vector<vector<int>> A;
    for(int i=0;i<2;i++){
    	vector<int> temp;
    	for(int j=0;i<m;j++){
    		cin>>input;
    		temp.push_back(input);
    	}
    	A.push_back(temp);
    	temp.clear();
    }
	return 0;
}
