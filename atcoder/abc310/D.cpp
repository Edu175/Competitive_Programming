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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll N=10;

ll g[N+5][N+5];
ll dp[N+5][(1ll<<N)+5];

ll f(ll t, ll mk){
	ll &res=dp[t][mk];
	if(res!=-1)return res;
	if(t==0){
		if(mk==0)res=1;
		else res=0;
		//cout<<t<<" "<<mk<<": "<<res<<"\n";
		return res;
	}
	if(mk==0)return res=0;
	/*fore(mki,0,1ll<<N){
		fore(i,0,N)if(mki&(1ll<<i)&&!(mk&(1ll<<i)))continue;
		if(mk==mki)continue;
		
	}*/
	res=0;
	vector<ll>a;
	fore(i,0,N)if(mk&(1ll<<i))a.pb(i);

	ll k=SZ(a);
	//cout<<t<<" "<<mk<<": sz="<<k<<" "<<a<<"\n";
	fore(b,1ll<<(k-1),1ll<<k){
		vector<ll>ai;
		ll mki=mk;
		fore(i,0,k)if(b&(1ll<<i)){
			ai.pb(a[i]);
			mki^=1ll<<a[i];
		}
		//cout<<t<<" "<<mk<<": "<<b<<" "<<mki<<": "<<ai<<"\n";
		ll flag=1;
		fore(i,0,SZ(ai))fore(j,0,SZ(ai))if(g[ai[i]][ai[j]])flag=0;
		if(flag)res+=f(t-1,mki);
	}
	//cout<<t<<" "<<mk<<": "<<res<<endl;
	return res;
}

int main(){FIN;
	ll n,t,m; cin>>n>>t>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u][v]=1;
		g[v][u]=1;
	}
	mset(dp,-1);
	cout<<f(t,(1ll<<n)-1)<<"\n";
	return 0;
}
