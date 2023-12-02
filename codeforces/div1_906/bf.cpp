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

stack<ll> G[MAXN],g[MAXN];
//ll t=3;
ll f(ll x){
	//fore(i,0,t)cout<<" ";
	//cout<<x<<"\n";
	if(!SZ(g[x])){
		//fore(i,0,t)cout<<" ";
		//cout<<"end\n";
		return x;
	}
	auto y=g[x].top(); g[x].pop();
	t++;
	ll ret=f(y);
	t--;
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	//cout<<"==========edges=================\n";
	fore(i,0,n){
		ll m; cin>>m;
		fore(j,0,m){
			ll x; cin>>x; x--;
			G[i].push(x);
			//cout<<i+1<<" "<<x<<"\n";
		}
	}
	//cout<<"==========edges=================\n";
	fore(i,0,n){
		fore(j,0,n)g[j]=G[j];
		t=3;
		//cout<<"\n"<<i<<":\n";
		cout<<f(i)+1<<" ";
	}
	cout<<"\n";
	return 0;
}
