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

ii ask(ll l, ll r){
	cout<<"? "<<l+1<<" "<<r<<endl;
	ll x,f; cin>>x;
	if(x==-1)exit(0);
	cin>>f;
	return {x,f};
}

ll n;
vv a;
const ll MAXN=2e5+5;
// ll vis[MAXN];
void fill(ll l, ll r, ll x){
	fore(i,l,r)a[i]=x;
}
void f(ll l, ll r, ll x, ll c){
	if(c==r-l){
		fore(i,l,r)a[i]=x;
		return;
	}
	vector<ii> qs;
	vv ss,es;
	ll cnt=0,w=-1;
	for(ll s=l;s<r;s+=c){
		ll e=min(s+c,r);
		qs.pb(ask(s,e));
		ss.pb(s);
		es.pb(e);
		if(qs.back().fst==x){
			cnt++;
			w=SZ(qs)-1;
		}
	}
	assert(cnt>0);
	ll qw=qs[w].snd;
	if(cnt==1&&qw!=c){
		ll s=ss[w];
		auto rq=ask(s,s+1);
		if(rq.fst!=x){
			qw=c-qw;
			w++;
		}
	}
	
	if(w){
		fill(es[w-1]-(c-qw),es[w-1],x);
		es[w-1]-=c-qw;
	}
	fill(ss[w],ss[w]+qw,x);
	ss[w]+=qw;
	fore(i,0,SZ(ss)){
		ll s=ss[i],e=es[i];
		if(e-s==0)continue;
		if(qs[i].fst==x)qs[i]=ask(s,e);
		f(s,e,qs[i].fst,qs[i].snd);
	}
}

int main(){FIN;
	cin>>n;
	a.resize(n);
	auto rq=ask(0,n);
	f(0,n,rq.fst,rq.snd);
	cout<<"! ";
	fore(i,0,n)cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
