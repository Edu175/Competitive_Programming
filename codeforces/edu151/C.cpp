#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

string s,l,r;
ll dp[15][MAXN];
ll to[MAXN][10]; // to[i][c] = first arg(c) >=i
ll n,m;
ll f(ll i, ll p){
	ll &res=dp[i][p];
	if(res!=-1)return res;
	if(i==m){
		if(p==n+1)return res=1;
		return res=0;
	}
	if(p>=n)return res=1;
	fore(j,l[i]-'0',r[i]-'0'+1)res=max(res,f(i+1,to[p][j]));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>s;
		n=SZ(s); cin>>m;
		cin>>l>>r;
		fore(i,0,m+3)fore(j,0,n+3)dp[i][j]=-1;
		fore(i,0,n+3)fore(j,0,10)to[i][j]=n+1;
		for(ll i=n-1;i>=0;i--){
			fore(j,0,10)to[i][j]=to[i+1][j];
			to[i][s[i]-'0']=i+1;
		}
		ll res=f(0,0);
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
