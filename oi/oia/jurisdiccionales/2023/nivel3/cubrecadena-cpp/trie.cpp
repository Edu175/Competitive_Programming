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

ll tr[MAXN][30], qidx=0, is[MAXN];
ll add(ll x, char c){
	ll &res=tr[x][c-'A'];
	if(res!=-1)return res;
	return res=++qidx;
}

string s;
ll n;

ll dp[MAXN];

ll f(ll i){
	ll &res=dp[i];
	if(res!=-1)return res;
	if(i==n)return res=0;
	res=f(i+1);
	ll x=0;
	fore(j,1,105){
		if(i+j>n)break;
		x=tr[x][s[i+j-1]-'A'];
		if(x==-1)break;
		if(is[x])res=max(res,f(i+j)+j);
	}
	return res;
}

int cubrecadena(string &S, vector<string> &a) {
	s=S;
	mset(dp,-1);
	mset(tr,-1);
	for(auto i:a){
		ll x=0;
		fore(j,0,SZ(i)){
			x=add(x,i[j]);
		}
		is[x]=1;
	}
	n=SZ(s);
	return n-f(0);
}
