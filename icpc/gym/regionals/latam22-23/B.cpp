#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=2e18;
struct LiChao{ // for minimum (for maximum just change the sign of lines)
	vv xs; ll n; vector<ii> st;
	LiChao(vv xs):xs(xs),n(SZ(xs)),st(4*n+5,{0,INF}){}
	ll eval(ii l, ll x){return l.fst*x+l.snd;}
	void add(ii l){
		ll k=1,s=0,e=n;
		while(1){
			ll m=(s+e)/2;
			auto &v=st[k];
			if(eval(l,xs[m])<eval(v,xs[m]))swap(v,l);
			if(e-s==1)break;
			k*=2;
			if(l.fst<v.fst)s=m,k++;
			else e=m;
		}
	}
	ll eval(ll i){
		ll k=1,s=0,e=n,x=xs[i];
		ll res=eval(st[k],x);
		while(e-s>1){
			ll m=(s+e)/2;
			k*=2;
			if(i<m)e=m;
			else s=m,k++;
			res=min(res,eval(st[k],x));
		}
		return res;
	}
};

int main(){
	ET
	ll n; cin>>n;
	vector<ii> a(n);
	vector<ii> sa(n);
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		a[i]={x,y};
		sa[i]={x,i};
	}
	sort(ALL(sa));
	vv pos(n),xs(n);
	fore(i,0,n)pos[sa[i].snd]=i,xs[i]=sa[i].fst;
	
	ll m; cin>>m;
	vector<ii> b(m);
	fore(i,0,m)cin>>b[i].fst>>b[i].snd;
	vv ls(n),rs(n);
	fore(i,0,n)ls[i]=-1,rs[i]=m;
	while(1){
		ll hay=0;
		vector<vv> ev(m);
		fore(i,0,n){
			auto &l=ls[i],&r=rs[i];
			if(r-l<=1)continue;
			// cout<<i<<"("<<l<<","<<r<<") ";
			hay=1;
			ll h=(l+r)/2;
			ev[h].pb(i);
		}
		// cout<<endl;
		if(!hay)break;
		LiChao lc(xs);
		fore(t,0,m){
			lc.add(b[t]);
			for(auto i:ev[t]){
				auto &l=ls[i],&r=rs[i];
				auto [x,y]=a[i];
				ll good=lc.eval(pos[i])>y;
				ll h=(l+r)/2;
				if(good)r=h;
				else l=h;
			}
		}
	}
	vector<vv> ans(m+1);
	fore(i,0,n)ans[rs[i]].pb(i);
	fore(i,0,m){
		auto v=ans[i];
		cout<<SZ(v)<<" ";
		for(auto j:v)cout<<j+1<<" ";
		cout<<"\n";
	}
	return 0;
}