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
int longet_balanced_string(string s){
if(s.length() <= 1) return 0;
    int curMax = 0;
    vector<int> longest(s.size(),0);
    for(int i=1; i < s.length(); i++){
        if(s[i] == '>' || s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if( (s[i] == '>' && s[i-1] == '<') ||
                (s[i] == ')' && s[i-1] == '(') ||
                (s[i] == ']' && s[i-1] == '[') ||
                (s[i] == '}' && s[i-1] == '{') ){
                longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                curMax = max(longest[i],curMax);
            }
            else{
                if( i-longest[i-1]-1 >= 0 && (
                    (s[i] == '>' && s[i-longest[i-1]-1] == '<') ||
                    (s[i] == ')' && s[i-longest[i-1]-1] == '(') ||
                    (s[i] == ']' && s[i-longest[i-1]-1] == '[') ||
                    (s[i] == '}' && s[i-longest[i-1]-1] == '{') ) ){
                    longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2];
                    curMax = max(longest[i],curMax);
                }
            }
        }
        //if s[i] == '<' or '(' or '[' or '{', skip it, because longest[i] must be 0
    }
    return curMax;
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   	string A;
   	cin>>A;
   	cout<<longet_balanced_string(A)<<endl;
	return 0;
}
