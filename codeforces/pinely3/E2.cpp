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

vector<ll> good[20];
ll tr[20];

int main(){FIN;
	fore(i,0,19){
		for(ll j=i;j<19;j+=i+1)tr[i]^=(1ll<<j);
	}
	fore(n,5,20){
		//cout<<n<<":\n";
		fore(mk,1,1ll<<n){
			ll s=0;
			fore(i,0,n)if((1ll<<i)&mk)s^=(tr[i]&((1ll<<n)-1));
			if(__builtin_popcountll(s)<=n/5)good[n].pb(mk);
			//cout<<mk<<" "<<s<<"\n";
		}
	}
	//cout<<SZ(good[19])<<"\nkhdgt\n";
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		set<ii>st;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			st.insert({u,v});
		}
		if(n<5){
			cout<<"-1\n";
			continue;
		}
		if(n>=20){
			cout<<n<<"\n";
			fore(i,0,n)cout<<i+1<<" ";
			cout<<"\n";
			continue;
		}
		ll res=-1;
		for(auto mk:good[n]){
			ll flag=1;
			for(auto [i,j]:st)if(((1ll<<i)&mk)&&!((1ll<<j)&mk)){
				flag=0;
				break;
			}
			if(flag){
				res=mk;
				break;
			}
		}
		if(res==-1)cout<<"-1\n";
		else {
			vector<ll>s;
			fore(i,0,n)if(res&(1ll<<i))s.pb(i+1);
			cout<<SZ(s)<<"\n"; imp(s);
		}
	}
	return 0;
}
