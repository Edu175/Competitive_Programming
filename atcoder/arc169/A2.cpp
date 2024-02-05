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
ll d[MAXN];

void dfs(ll x){
	for(auto y:g[x]){
		d[y]=d[x]+1;
		dfs(y);
	}
}

void ans(ll x){
	if(x>0)cout<<"+\n";
	else if(x<0)cout<<"-\n";
	else cout<<"0\n";
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
	}
	d[0]=0;
	dfs(0);
	vector<ll>sd(n);
	fore(i,0,n)sd[d[i]]+=a[i];
	ll nz=-1;
	for(ll i=n-1;i>=0;i--)if(sd[i]){
		nz=i;
		break;
	}
	if(nz!=-1){
		ans(sd[nz]);
		return 0;
	}
	ll r=1;
	fore(i,0,100)r=r*10%(n-1);
	ll add=0;
	for(auto i:g[0])if(i<=r)add+=a[i];
	ans(add);
	return 0;
}
