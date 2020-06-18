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

int solve(string s){
	int len = s.length();
	int dp[len][len];
	memset(dp,0,sizeof dp);
	for(int i=0;i<len;i++){
		dp[i][i] = true;
	}
	for(int i=0;i<len-1;i++)
		if(s[i]==s[i+1])
			dp[i][i+1] = true;
	for(int i=3;i<=len;i++){
		for(int j=0;j<=len-i;j++){
			int l = i+j-1;
			if(s[j]==s[l])
				dp[j][l] = dp[j+1][l-1];
			else
				dp[j][l] = false;
		}
	}
	vector<int> pal(len,len);
	pal[len-1]=0;
	for(int i=len-2;i>=0;i--){
		if(dp[i][len-1])
			pal[i]=0;
		else{
			for(int j=i;j<len-1;j++){
				if(dp[i][j])
					pal[i] = min(pal[i],1+pal[j+1]);
			}
		}
	}
	for(int i=0;i<len;i++)
		cout<<pal[i]<<" ";
	cout<<endl;
	return pal[0];
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   	string A;
   	cin>>A;
   	cout<<solve(A)<<endl;
	return 0;
}
