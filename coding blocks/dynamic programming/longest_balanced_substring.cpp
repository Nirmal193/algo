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



int longest_balanced_substring(string A){
	int len = A.size();
	vector<char> stk;
	vector<int> dp(len,0);
	stk.push_back(A[0]);
	int c = 0;
	for(int i=1;i<len;i++){
		if(A[i] == '{' || A[i] == '(' || A[i] =='[')
			stk.push_back(A[i]);
		else {
			if(stk.back() == '(' && A[i] == ')'){
				c = c+2;
				stk.pop_back();
			}
			else if(stk.back() == '{' && A[i] == '}'){
				stk.pop_back();
				c = c+2;
			}
			else if(stk.back() == '[' && A[i] == ']'){
				stk.pop_back();
				c = c+2;
			}
			else{
				c = 0;
				stk.clear();
			}
		}
		dp[i] = MAX(dp[i-1],c);
	}
	for(int i=0;i<len;i++){
		cout<<A[i]<<" "<<dp[i]<<endl;
	}
	return dp[len-1];
}
int main(){
  string A;
  cin>>A;
  cout<<longest_balanced_substring(A)<<endl;
  return 0;
}
