#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<"\n";}
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll sq(ll n){return n*n;}
int main(){ET;
	ll n,m,q; cin>>n>>m>>q;
	vv oc(m);
	oc[0]=n;
	vv col(n,0);
	set<ii>st={{0,n}};
	auto add=[&](ii a, ll t){
		// cout<<"add "<<a.fst<<","<<a.snd<<" "<<t<<"\n";
		// impr(st);
		vector<ii>out;
		for(auto it=prev(st.lower_bound({a.fst+1,0}));
		it!=st.end()&&it->fst<a.snd;it++)out.pb(*it);
		// cout<<"out: ";;for(auto i:out)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		for(auto i:out)st.erase(i),oc[col[i.fst]]-=i.snd-i.fst;
		
		ii b=out.back();
		auto pone=[&](ii c, ll k){
			if(c.snd==c.fst)return;
			st.insert(c);
			col[c.fst]=k;
			oc[col[c.fst]]+=c.snd-c.fst;
		};
		pone({a.snd,b.snd},col[b.fst]);
		b=out[0];
		pone({b.fst,a.fst},col[b.fst]);
		col[a.fst]=t;
		oc[t]+=a.snd-a.fst;
		st.insert(a);
		// impr(st);
		// imp(oc);
		// cout<<"\n";
	};
	while(q--){
		ll p,x,a,b; cin>>p>>x>>a>>b; p--,x--;
		ll s=oc[p];
		ll m1=(a+sq(s))%n;
		ll m2=(a+sq(s+b))%n;
		if(m1>m2)swap(m1,m2);
		m2++;
		add({m1,m2},x);
	}
	ll mx=0;
	fore(i,0,m)mx=max(mx,oc[i]);
	cout<<mx<<"\n";
}