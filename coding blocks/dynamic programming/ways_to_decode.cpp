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
int Ways_to_decode(string A){
	int len = A.length();
    vector<int> dp(len+1,0);
    dp[0] = dp[1] = 1;
    if(A[0] == '0')
        return 0;
    for(int i=2;i<=len;i++){
        if(A[i-1]!='0')
            dp[i] = dp[i-1];
        if((A[i-2]=='2' && A[i-1]<='6' )|| A[i-2]=='1')
            dp[i] = dp[i]+dp[i-2];
        if(dp[i] == 0)
            return 0;
    }
    return dp[len];
}
int main(){
 	// freopen("input.txt","r",stdin);
  //   freopen("output.txt","w",stdout);
  string str;
  cin>>str;
  cout<<Ways_to_decode(str)<<endl;
	return 0;
}
