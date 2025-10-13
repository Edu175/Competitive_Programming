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
const ll C=20,H=1000,SEE=50;

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll m=min(n,C);
	vector<ii>all;
	fore(mk,0,1ll<<m){
		ll sum=0;
		fore(i,0,m){
			if(mk>>i&1)sum+=a[i];
			else sum-=a[i];
		}
		all.pb({sum,mk});
	}
	sort(ALL(all));
	auto is=[&](ll v){
		auto ptr=lower_bound(ALL(all),(ii){v,-1});
		return ptr!=all.end()&&ptr->fst==v;
	};
	ll mn=0;
	fore(i,0,SZ(all))if(abs(all[i].fst)<abs(all[mn].fst))mn=i;
	cout<<"ventana\n";
	fore(i,mn-SEE,mn+SEE)cout<<all[i].fst<<" ";;cout<<"\n";
	// fore(i,0,H){
	// 	if(!is(i))cout<<"no esta "<<i<<"\n";
	// 	if(!is(-i))cout<<"no esta "<<-i<<"\n";
	// }
	return 0;
}
