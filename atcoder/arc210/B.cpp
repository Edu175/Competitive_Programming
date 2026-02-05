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

void erase(multiset<ll> &st, ll x){
	st.erase(st.find(x));
}
bool count(multiset<ll> &st, ll x){
	return st.find(x)!=st.end();
}

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	vv a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	vv sd=a;
	for(auto i:b)sd.pb(i);
	sort(ALL(sd));
	vector<multiset<ll>> st(3);
	ll sum=0;
	auto saca=[&](ll w, ll v){
		erase(st[w],v);
		if(w!=1)sum-=v;
	};
	auto pone=[&](ll w, ll v){
		st[w].insert(v);
		if(w!=1)sum+=v;
	};
	fore(i,0,SZ(sd)){
		ll w=1;
		if(i<n/2)w=0;
		if(i>=SZ(sd)-n/2)w=2;
		pone(w,sd[i]);
	}
	cerr<<"inicial "<<sum<<"\n";
	while(q--){
		ll t,i,x; cin>>t>>i>>x; i--;
		auto &arr=t==1?a:b;
		ll v=arr[i];
		ll wh=-1;
		fore(w,0,3)if(wh==-1){
			if(count(st[w],v)){
				saca(w,v);
				wh=w;
			}
		}
		assert(wh!=-1);
		arr[i]=x; v=x;
		pone(wh,v);
		fore(_,0,2)fore(i,0,2){
			auto &a=st[i];
			auto &b=st[i+1];
			ll l=*a.rbegin();
			ll r=*b.begin();
			if(l>r){
				saca(i,l); saca(i+1,r);
				pone(i,r); pone(i+1,l);
			}
		}
		// fore(w,0,3){
		// 	cout<<w<<": ";
		// 	imp(st[w])
		// }
		cout<<sum<<"\n";
	}
	return 0;
}
