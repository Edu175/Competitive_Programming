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
const ll MAXN=250005;

ll a[MAXN];
vector<ll> g[MAXN];
ll s[MAXN];

void dfs(ll x){
	s[x]=a[x];
	for(auto y:g[x]){
		dfs(y);
		s[x]+=s[y];
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
	}
	dfs(0);
	s[0]-=a[0];
	if(s[0]>0)cout<<"+\n";
	else if(s[0]<0)cout<<"-\n";
	else {
		ll r=1;
		fore(i,0,100)r=r*10%(n-1);
		ll add=0;
		for(auto x:g[0])if(x<r)add+=a[x];
		if(add>0)cout<<"+\n";
		else if(add<0)cout<<"-\n";
		else {
			if(a[0]>0)cout<<"+\n";
			else if(a[0]<0)cout<<"-\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
