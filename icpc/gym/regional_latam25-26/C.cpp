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
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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
bool les(ii a, ii b){
	return a.fst*b.snd<b.fst*a.snd;
}
const ll MAXH=1e5+5;

int main(){FIN;
	ll n,s,k; cin>>n>>s>>k;
	vv h(n),l(n),r(n),c(n);
	vector<ii> ev;
	fore(i,0,n){
		cin>>h[i]>>l[i]>>r[i];
		c[i]=k/h[i];
		ev.pb({i,+1});
		ev.pb({i,-1});
	}
	sort(ALL(ev),[&](ii e1, ii e2)-> bool {
		auto [i1,w1]=e1;
		auto [i2,w2]=e2;
		ll t1=w1==1?l[i1]:r[i1];
		ll t2=w2==1?l[i2]:r[i2];
		ii f1={t1,h[i1]};
		ii f2={t2,h[i2]};
		if(les(f1,f2))return 1;
		if(les(f2,f1))return 0;
		return w1>w2;
	});
	STree sc(MAXH),sv(MAXH);
	ii res; ll did=0;
	for(auto [i,w]:ev){
		sc.upd(h[i],w*c[i]);
		sv.upd(h[i],w*h[i]*c[i]);
		ll lo=0,hi=MAXH;
		while(hi-lo>1){
			ll m=(lo+hi)/2;
			if(sc.query(0,m+1)>=s)hi=m;
			else lo=m;
		}
		ll m=hi;
		if(m>=MAXH)continue;
		ll sum=sc.query(0,m);
		ll val=sv.query(0,m);
		ll d=s-sum;
		assert(d>=0&&sc.query(m,m+1)>=d);
		val+=m*d;
		ll t=w==1?l[i]:r[i];
		ii cur={val*t,h[i]};
		if(!did||les(cur,res))res=cur;
		did=1;
	}
	if(!did)cout<<"*\n";
	else {
		ll g=gcd(res.fst,res.snd);
		res.fst/=g,res.snd/=g;
		cout<<res.fst<<" "<<res.snd<<"\n";
	}
	return 0;
}