#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v){for(auto x:v)cout<<x<<" "; cout<<"\n";}
#define showp(v){for(auto x:v)cout<<x.fst<<","<<x.snd<<" "; cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;

struct LiChao{ // now it is for max
	vv xs; ll n; vector<ii> st;
	LiChao(vv xs):xs(xs),n(SZ(xs)),st(4*n+5,{0,INF}){}
	ll eval(ii l, ll x){return l.fst*x+l.snd;}
	void add(ii l){
		l.fst*=-1;
		l.snd*=-1;
		ll k=1,s=0,e=n;
		while(1){
			ll m=(s+e)/2;
			auto &v=st[k];
			if(eval(l,xs[m])<eval(v,xs[m]))swap(v,l);
			if(e-s==1)break;
			k<<=1;
			if(l.fst<v.fst)s=m,k++;
			else e=m;
		}
	}
	ll eval(ll i){ // x in xs
		ll k=1,s=0,e=n,x=xs[i];
		ll res=eval(st[k],x);
		while(e-s>1){
			ll m=(s+e)/2;
			k<<=1;
			if(i<m)e=m;
			else s=m,k++;
			res=min(res,eval(st[k],x));
		}
		return -res;
	}
};

ll solve(vector<ii> a){
	// cout<<"solve "; showp(a);
	vv xs,ys;
	for(auto [x,y]:a)xs.pb(x),ys.pb(y);
	sort(ALL(xs)); xs.resize(unique(ALL(xs))-xs.begin()); 
	sort(ALL(ys)); ys.resize(unique(ALL(ys))-ys.begin()); 
	auto get_idx=[&](ll x, vv &a){return lower_bound(ALL(a),x)-a.begin();};
	
	LiChao qx(xs),qy(ys);
	ll ant=0;
	ll n=SZ(a);
	fore(i,0,n){
		auto [x,y]=a[i];
		qx.add({y,ant});
		qy.add({x,ant});
		ll ix=get_idx(x,xs);
		ll iy=get_idx(y,ys);
		ll candx=qx.eval(ix);
		ll candy=qy.eval(iy);
		ll cur=max(candx,candy);
		ant=cur;
	}
	// cout<<"= "<<ant<<"\n\n";
	return ant;
}

int main(){
    JET
    ll n; cin>>n;
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	ll mx=max_element(ALL(a))-a.begin();
	rotate(a.begin(),a.begin()+mx,a.end());
	ll res1=solve(a);
	rotate(a.begin(),a.begin()+1,a.end());
	ll res2=solve(a);
	ll res=max(res1,res2);
	cout<<res<<"\n";
	return 0;
}
