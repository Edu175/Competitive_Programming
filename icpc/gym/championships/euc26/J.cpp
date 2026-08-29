#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ll k;
vv dp;
void sup_dp(){
	fore(j,0,k)for(ll mk=(1ll<<k)-1;mk>=0;mk--){
		if(!(mk>>j&1))dp[mk]+=dp[mk|(1ll<<j)];
	}
}

int main(){
	JET
	ll n,m; cin>>n>>k>>m;
	dp.resize(1ll<<k,0);
	vector<ii> ev;
	fore(i,0,k){
		ll z; cin>>z;
		fore(_,0,z){
			ll l,r; cin>>l>>r; r++;
			ev.pb({l,i});
			ev.pb({r,-i-1});
		}
	}
	sort(ALL(ev));
	ll all=(1ll<<k)-1;
	ll mk=0,tot=0;
	fore(id,0,SZ(ev)){
		auto [t,ch]=ev[id];
		ll fg=0;
		if(ch<0)fg=1,ch=-ch-1;
		mk^=1ll<<ch;
		if(id+1<SZ(ev)){
			ll len=ev[id+1].fst-t;
			if(len&&mk){
				tot+=len;
				ll u=all^mk;
				ll cant=0;
				fore(i,0,k)if(mk>>i&1){
					ll ui=u|(1ll<<i);
					dp[ui]-=len;
					cant++;
				}
				dp[u]+=(cant-1)*len;
			}
		}
	}
	sup_dp();
	ll res=0;
	fore(mk,0,1ll<<k){
		ll am=tot+dp[mk];
		if(am>=m)res++;
	}
	cout<<res<<"\n";
	return 0;
}