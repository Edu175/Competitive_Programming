#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;

ll ft[MAXN+1];
void upd(ll i0,ll v){
	for(ll i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
ll get(ll i0){
	ll ret=0;
	for(ll i=i0;i;i-=i&-i)ret+=ft[i];
	return ret;
}
ll get_sum(ll i0,ll i1){
	return get(i1)-get(i0);
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i],upd(i,a[i]);
	while(q--){
		ll x; cin>>x;
		if(x==1){
			ll i,v; cin>>i>>v; i--;
			upd(i,v-a[i]);
			a[i]=v;
		}
		else {
			ll s,e; cin>>s>>e; s--;
			cout<<get_sum(s,e)<<"\n";
		}
	}
	return 0;
}
