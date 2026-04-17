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
		ll n,k; cin>>n>>k;
		if(k<n||k>=2*n){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		vv a;
		k-=n;
		vv oc(n,2);
		auto put=[&](ll v){
			assert(oc[v]>0);
			a.pb(v),oc[v]--;
		};
		if(k){
			put(0);
			put(1);
			fore(i,1,k){
				// ll p=2*i;
				ll v=i+1;
				put(v);
				put(v-2);
			}
		}
		fore(i,0,n)fore(_,0,oc[i])a.pb(i);
		for(auto i:a)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
