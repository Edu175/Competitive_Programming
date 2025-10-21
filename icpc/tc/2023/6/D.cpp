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

pair<ii,ll> get(vector<ii> a, ll x){// l,r
	ll n=SZ(a);
	ll der=-5; ii izq={n+5,n+5};
	fore(i,0,n){
		ll z=(x+a[i].fst-1)/a[i].fst;
		if(i+z<=n)der=i;
		izq=min(izq,ii({i+z,i}));
	}
	swap(izq.fst,izq.snd);
	return {izq,der};
}

pair<vv,vv> get(vv a, ll x1, ll x2){
	ll n=SZ(a);
	vector<ii> b;
	fore(i,0,n)b.pb({a[i],i});
	sort(ALL(b));
	auto izq=get(b,x1).fst;
	auto der=get(b,x2).snd;
	if(izq.snd<=der){
		vv L,R;
		fore(i,izq.fst,izq.snd)L.pb(b[i].snd);
		fore(i,der,n)R.pb(b[i].snd);
		return {L,R};
	}
	return {{},{}};
}

int main(){FIN;
	ll n,x1,x2; cin>>n>>x1>>x2;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	auto [L,R]=get(a,x1,x2);
	if(!SZ(L)){
		tie(L,R)=get(a,x2,x1);
		swap(L,R);
	}
	if(!SZ(L)){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n"<<SZ(L)<<" "<<SZ(R)<<"\n";
	
	for(auto i:L)cout<<i+1<<" ";;cout<<"\n";
	for(auto i:R)cout<<i+1<<" ";;cout<<"\n";
	
	return 0;
}
