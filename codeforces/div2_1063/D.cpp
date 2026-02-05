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
#define minig(a,b) a=min(a,b)
ll ask(ll l, ll r){
	if(r-l<=0)return 0;
	cout<<"? "<<l+1<<" "<<r<<endl;
	ll ret; cin>>ret;
	return ret;
}
bool cont(ii a, ii b){
	return a.fst<=b.fst&&b.snd<=a.snd;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ii> a(q);
		fore(i,0,q){
			cin>>a[i].fst>>a[i].snd,a[i].fst--;
		}
		sort(ALL(a));
		auto _a=a; a.clear();
		for(auto i:_a){
			while(SZ(a)&&cont(i,a.back()))a.pop_back();
			if(!SZ(a)||!cont(a.back(),i))a.pb(i);
		}
		q=SZ(a);
		ll l=0,r=q-1;
		while(l<=r){
			ll m=(l+r)/2;
			auto [s,e]=a[m];
			if(ask(0,e)>ask(s,n))r=m-1;
			else l=m+1;
		}
		vv cand={l,r};
		ll res=0;
		for(auto i:cand)if(i>=0&&i<q)res=max(res,ask(a[i].fst,a[i].snd));
		cout<<"! "<<res<<endl;
	}
	return 0;
}
