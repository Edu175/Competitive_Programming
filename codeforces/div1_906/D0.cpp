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
const ll MAXN=1e5+5;

queue<ll> g[MAXN];
ll dp[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res!=-1)return res;
	//cout<<x<<"\n";
	if(!SZ(g[x])){
		//cout<<"end\n";
		return x;
	}
	auto y=g[x].front(); g[x].pop();
	return f(y);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		ll m; cin>>m;
		fore(j,0,m){
			ll x; cin>>x; x--;
			g[i].push(x);
		}
	}
	mset(dp,-1);
	fore(i,0,n){
		ll &res=dp[i];
		res=f(i);
		cout<<res+1<<" ";
	}
	cout<<"\n";
	return 0;
}
