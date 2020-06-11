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

int **dp;
int edit_distance(string A,string B,int i,int j,int **dp){
	if(i<0 || j <0)
		return MAX(i+1,j+1);
	if(dp[i][j]!=0)
		return dp[i][j];
	if(A[i] == B[j]){
		dp[i][j] = edit_distance(A,B,i-1,j-1,dp);
		return dp[i][j];
	}
	else{
		dp[i][j] = MIN(edit_distance(A,B,i-1,j,dp),MIN(edit_distance(A,B,i-1,j-1,dp),edit_distance(A,B,i,j-1,dp)))+1;
		return dp[i][j];
	}
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   	string A,B;
   	cin>>A>>B;
   	int m = A.length();
   	int n = B.length();
   	dp = new int*[m];
	for(int i = 0; i < m; i++)
    	dp[i] = new int[n];
    for(int i=0;i<m;i++)
    	for(int j=0;j<n;j++)
    		dp[i][j] = 0;
   	cout<<edit_distance(A,B,A.length()-1,B.length()-1,dp)<<endl;
	return 0;
}
