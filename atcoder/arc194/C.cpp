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
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
int main(){FIN;
	ll n; cin>>n;
	vv a(n),b=a,c=a;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	vector<ii> sc={{-1e18,-1}};
	fore(i,0,n){
		cin>>c[i];
		sc.pb({c[i],i});
		sc.pb({-c[i],i});
	}
	ll m=SZ(sc);
	sort(ALL(sc));
	vv pos(n),posN(n);
	STree st(m),cant(m);
	fore(idx,0,m){
		auto [v,i]=sc[idx];
		if(i!=-1)(v<0?posN:pos)[i]=idx;
	}
	ll res=0;
	auto agr=[&](ll i, ll v){
		ll p=(v<0?posN:pos)[i];
		ll sum=st.query(0,p);
		res+=sum;
		ll val=v*c[i];
		st.upd(p,val);
		cant.upd(p,1);
		ll q=cant.query(p,m);
		res+=q*val;
	};
	ll s=0;
	fore(i,0,n){
		if(a[i])s+=c[i];
	}
	st.upd(0,s);
	vector<ii> both;
	fore(i,0,n){	
		if(a[i]&&!b[i])agr(i,-1);
		if(!a[i]&&b[i])agr(i,1);
		if(a[i]&&b[i])both.pb({c[i],i});
	}
	sort(ALL(both));
	reverse(ALL(both));
	ll ans=res;
	for(auto [sfsadf,i]:both){
		agr(i,-1);
		agr(i,+1);
		ans=min(ans,res);
		// cerr<<i<<": "<<res<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
