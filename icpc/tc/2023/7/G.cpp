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
const ll MAXN=1e5+5;
struct info{
	ll n;
	vv h; // ordered v's
	vv lwb;
	info(ll n):n(n),h(n),lwb(n+2,n){lwb[0]=0;}
	void add(ll v){ // sumale uno
		ll p=lwb[v+1]-1;
		assert(h[p]==v);
		h[p]++;
		lwb[v+1]--;
	}
	void rem(ll v){ // restale uno
		ll p=lwb[v];
		assert(h[p]==v);
		h[p]--;
		lwb[v]++;
	}
	ll query(ll k){
		// cout<<"query:\n";; imp(h) imp(lwb) cout<<"\n";
		ll mn=-1;
		for(ll p=lwb[1]; p+k<n; p=lwb[h[p]+1]){
			ll cur=h[p+k]-h[p];
			if(mn==-1||cur<mn)mn=cur;
		}
		return mn;
	}
};
info pinga(1);
ll oc[MAXN];
ll a[MAXN];
ll l,r,t;
void add(ll i){
	// cout<<"add "<<i<<endl;
	ll v=a[i];
	pinga.add(oc[v]++);
}
void rem(ll i){
	// cout<<"rem "<<i<<endl;
	ll v=a[i];
	pinga.rem(oc[v]--);
}
vector<array<ll,3>> upds; // pos, before, after

void upd(ll t, ll w){ // 1 add, -1 rem
	auto [i,u,v]=upds[t];
	if(l<=i&&i<r)rem(i);
	a[i]=w==1?v:u;
	if(l<=i&&i<r)add(i);
}

struct qu{ll l,r,t,k,id;};
vv mos(vector<qu> qs, ll n){
	ll d=cbrt(n*n)+.5;
	// fore(i,0,SZ(qs))qs[i].id=i;
	vv ans(SZ(qs));
	sort(ALL(qs),[&](const qu &a, const qu &b){
		ll al=a.l/d,ar=a.r/d;
		ll bl=b.l/d,br=b.r/d;
		if(al!=bl)return al<bl;
		if(ar!=br)return al&1?ar>br:ar<br;
		return (al^br)&1?a.t>b.t:a.t<b.t;
	});
	l=0,r=0,t=0;
	for(auto q:qs){
		// cout<<"\n\n"<<q.id<<": "<<q.l<<","<<q.r<<" "<<q.t<<": "<<q.k<<endl;
		while(q.l<l)add(--l);
		while(r<q.r)add(r++);
		
		while(l<q.l)rem(l++);
		while(q.r<r)rem(--r);
		
		while(t<q.t)upd(t++,1);
		while(t>q.t)upd(--t,-1);
		
		ans[q.id]=pinga.query(q.k);
	}
	return ans;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	pinga=info(n);
	fore(i,0,n)cin>>a[i];
	vv _a(n); fore(i,0,n)_a[i]=a[i];
	vector<qu> qs;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll l,r,k; cin>>l>>r>>k; l--; k--;
			qs.pb({l,r,SZ(upds),k,SZ(qs)});
		}
		else {
			ll p,x; cin>>p>>x; p--;
			upds.pb({p,a[p],x});
			a[p]=x;
		}
	}
	// for(auto q:qs)cout<<q.id<<": "<<q.l<<","<<q.r<<" "<<q.t<<": "<<q.k<<endl;
	// for(auto [p,u,v]:upds)cout<<p<<" "<<u<<","<<v<<endl;
	
	fore(i,0,n)a[i]=_a[i];
	auto ans=mos(qs,n);
	for(auto i:ans)cout<<i<<"\n";
	return 0;
}
