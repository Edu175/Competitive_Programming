#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

string s;
set<string>st;
ll n;

ll dp[MAXN];

ll f(ll i){
	ll &res=dp[i];
	if(res!=-1)return res;
	if(i==n)return res=0;
	res=f(i+1);
	string t;
	fore(j,1,105){
		if(i+j>n)break;
		t.pb(s[i+j-1]);
		if(st.count(t))res=max(res,f(i+j)+j);
	}
	return res;
}

int cubrecadena(string &S, vector<string> &A) {
	s=S;
	for(auto i:A){
		if(!st.count(i))st.insert(i);
	}
	mset(dp,-1);
	n=SZ(s);
	return n-f(0);
}
