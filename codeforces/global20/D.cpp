#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		reverse(ALL(a));
		reverse(ALL(b));
		vv sac(n);
		ll po=0,fg=1;
		fore(i,0,n){
			ll v=b[i];
			while(v!=a[po]){
				if(sac[a[po]]==0){fg=0;break;}
				sac[a[po]]--;
				po++;
			}if(!fg)break;
			assert(v==a[po]);
			sac[v]++;
		}
		if(fg)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
