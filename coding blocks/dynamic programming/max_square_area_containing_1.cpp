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
int solution(vector<vector<int>> A){
	int m = A.size();
	int n = A[0].size();
	vector<vector<int>> dp (m+1,vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(A[i-1][j-1] == 1){
				dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
			}
		}
	}
	int ans = INT_MIN;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ans = max(ans,dp[i][j]);
		}
	}
	return ans*ans;
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   	int input;
   	int a,b;
   	vector<vector<int>> A;
   	cin>>a>>b;
   	for(int i=0;i<a;i++){
   		vector<int> temp;
   		for(int j=0;j<b;j++){
   			cin>>input;
   			temp.push_back(input);
   		}
   		A.push_back(temp);
   	}
   	cout<<solution(A)<<endl;
	return 0;
}
