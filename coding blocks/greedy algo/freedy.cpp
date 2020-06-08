#include<iostream>
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
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
typedef long long int ll;

const int max_size = 1000001;
vector<long long> prime;
vector<long long> isprime(max_size,true);
vector<long long> SPF(max_size);

int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
int gcd(int a, int b,int &x,int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int x1,y1;
	int ans = gcd(b,a%b,x1,y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return ans;
}
bool deph(int a,int b,int c,int &x,int &y,int &g){
	g = gcd(ABS(a),ABS(b),x,y);
	/*if(g==1){
		if(c%g == 0 && c%a!=0 || c%b!=0)
			return false;
	}*/
	if(c%g)
		return false;
	x = x*(c/g);
	y = y*(c/g);
	if(a<0)
		x = -x;
	if(b<0)
		y = -y;
	return true;
}
void modifiedSieve(int n){
	isprime[0] = isprime[1] = false;
	for(int i=2; i<=n; i++){
		if(isprime[i]){
			prime.push_back(i);
			SPF[i] = i;
		}
		for(int j = 0; j<(int)prime.size() && prime[j]*i <= n && prime[j] <= SPF[i]; j++){
			isprime[i*prime[j]] = false;
			SPF[i*prime[j]] = prime[j];
		}
	}
}
vector<int> generate_prime(int l,int r){
	int n = sqrt(r)+1;
	vector<bool>prime(n,true);
	prime[0] = prime[1] = false;
	for(int i=2;i*i<=n;i++){
		if(prime[i])
		for(int j = i*i;j<=n;j+=i){
			prime[j] = false;
		}
	}
	vector<bool> seg_prime(r-l,true);
	for(int i=0;i<prime.size();i++){
		if(prime[i])
			for(int j=l;j<=r;j+=i)
				cout<<j<<" ";
	}
	vector<int> ans;
	for(int i=0;i<seg_prime.size();i++){
		if(seg_prime[i])
			ans.pb(l+i-1);
	}
	return ans;
}
vector<int> Zarray(string s){
	int l = 0;
	int r = 0;
	vector<int> z(s.length(),0);
	int len = s.length();
	z[0] = len;
	for(int i=1; i<len; i++){
		if(i>r){
			int j=0;
			while((i+j)<len && s[i+j] == s[j])
				j++;
			z[i] = j;
			l = i;
			r = i+j-1;
		}
		else{
			int k = i-l;
			if(z[k] < (r-i+1))
				z[i] = z[k];
			else{
				int p1 = r-i;
				int p2 = r+1;
				while(p2<len && s[p1] == s[p2]){
					p1++;
					p2++;
				}
				z[i] = p2-i+1;
				l = i;
				r = p2-1;
			}
		}
	}
	return z;
}
string lcp(vector<string> A){
		int len = A.size();
		string temp = "";
		int res = INT_MAX;
		for(int i=1; i<len; i++){
			temp = A[i-1]+A[i];
			int n = A[i-1].size();
			vector<int> tmp = Zarray(temp);
			int x = INT_MIN;
			for(int i = n-1; i<tmp.size();i++){
				x = max(tmp[i],x);
			}
			x = MIN(x,A[i].length());
			res = min(res,x);
		}
		if(res!=0)
			return A[0].substr(0,res);
		else
			return "";
}
string sol(string A){
	queue<char> q;
	q.push(A[0]);
	unordered_map<char,int> s;
	s[A[0]] = 1;
	string ans = "";
	ans+=A[0];
	for(int i=1; i<A.length(); i++){
		s[A[i]]++;
		if(q.front() == A[i])
			q.pop();
		else
			q.push(A[i]);
		while(!q.empty() && s[q.front()]>=2){
			q.pop();
		}
		if(!q.empty())
			ans += q.front();
		else
	{		char ch = '#';
			ans += ch;
		}
	}
	return ans;
}
string soln(string A){
	int len = A.length();
    int counter = 0;
    for(int i=0;i<len/2;i++){
        if(A[i] != A[len-i-1])
        counter++;
    }
    if(counter<=1 && len%2!=0)
        return "YES";
    else
        return "NO";
}
string solns(string A,string B){
	string ans = "";
	int i=1;
	ans+=A[0];
	while(A[i]<B[0] && i<A.length()){
		ans+=A[i];
		i++;
	}
	if(i==0)
		ans = A;
	return ans+B[0];
}
int soln1(vector<int> A){
	vector<int> flag(A.size(),1);
    for(int i=1; i<A.size();i++){
        if(A[i]>A[i-1] && flag[i] <= flag[i-1])
            flag[i] = flag[i-1]+1;
    }
    for(int i=A.size()-2; i>=0;i--){
        if(A[i]>A[i+1] && flag[i] <= flag[i+1])
             flag[i] = flag[i+1]+1;;
    }
    int ans = 0;
    for(int i:flag){
    	ans+=i;
    }
    return ans;
}
int seats(string str){
	int l=0,r=0;
	bool f1 = false;
	int len = str.length();
	for(int i=0;i<len;i++){
		if(str[i]=='x' && f1 == false){
			l = i;
			f1 = true;
		}
		else if(str[i]=='x'){
			r = i;
		}
	}
	int mid = l+(l-r)/2;
	int counter = 0;

	return 0;
}
int tmp1(int n1){
	return (n1*(n1+1))/2;
}
vector<int> sol2(int A,int B,vector<int> C){
	vector<int> r;
	vector<int> temp(C);
	int maximum = 0,minimum = 0;
	int len = C.size();
	while(A>0){
		int m1 = INT_MIN,m2 = INT_MAX;
		int idx1 = -1,idx2 = -1;
		for(int i=0; i<len; i++){
			if(m1<C[i]){
				m1 = C[i];
				idx1 = i;
			}
			if(temp[i]<m2 && temp[i] >0){
				m2 = temp[i];
				idx2 = i;
			}
		}
		maximum += m1;
		minimum += m2;
		--temp[idx2];
		--C[idx1];
		A--;
	}
	r.push_back(maximum);
	r.push_back(minimum);
	return r;
}
int sol3(string A, int B){
	int ans = 0;
	int len = A.length();
	int i=0;
	while(i<len){
		if(A[i] == '0'){
			int t = i+B;
			if(i+B>len){
				return -1;
			}
 			for(int j = i;j<t;j++){
				if(A[j] == '0')
					A[j] = '1';
				else
					A[j] = '0';
			}
			++ans;
		}
		++i;
	}
	return ans;
}
int sol4(vector<int> A){
	int ans = 1;
	int len = A.size();
	int counter = 0;
	if(A[0]==0)
		return -1;
	int prev = 1;
	counter = A[prev-1];
	while(counter<len-1){
		++ans;
		int m = INT_MIN;
		cout<<prev<<" "<<counter<<endl;
		for(int i=prev;i<=counter;i++){
			if((A[i]+i)>=len){
				return ans;
			}
			if(A[i]+i > m && A[A[i]+i]!=0){
				m = A[i]+i;
				prev = i+1;
			}
		}
		/*if(m == INT_MIN){
			return -1;
		}*/
		counter = m;
	}

	return ans;
}
int median(string A,int start,int end,int counter){
	counter = (counter/2)+1;
	int ans = 0;
	while(counter>0){
		if(A[start] == 'x'){
			counter--;
			ans = start;
		}
		start++;
	}
	return ans;
}
 int sol5(string A){
	int start = 0;
	int end = 0;
	bool flag = true;
	int counter = 0;
	int len = A.length();
	for(int i=0;i<len;i++){
		if(A[i] == 'x' && flag){
			start = i;
			flag = false;
		}
		if(A[i] == 'x'){
			end = i;
			counter++;
		}
	}
	int m = median(A,start,end,counter);
	int ans = 0;
	int x = m-(counter/2);
	for(int i=start;i<=end;i++){
		if(A[i] == 'x'){
			ans += ABS((x-i));
			x++;
		}
	}
	return ans;
}
void solve(){
	string str;
	cin>>str;
	cout<<sol5(str)<<endl;
}
int main(){
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  	solve();
	return 0;
}
