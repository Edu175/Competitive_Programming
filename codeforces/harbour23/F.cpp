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
// const ll INF=1e8;
struct STree{
	int n;
	ll NEUT;
	vector<ll>t; vv a;
	ll oper(ll i, ll j){return a[i]>a[j]?i:j;}
	// STree(int N):n(N+1),NEUT(N),t(2*n+5,NEUT),a(n){}
	STree(ll N){
		a=vv(N,-1);
		a.pb(-1);
		n=SZ(a);
		NEUT=n-1;
		
		t=vv(2*n+5);
		fore(i,0,n)t[n+i]=i;
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
	void upd(int p, ll v){
		for(a[p]=v,p+=n;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
const ll MAXN=1e6+5;
int ft[MAXN+1]; // add dimension for multi-d
void upd(int i0, int v){ // add v to i0th element
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;//+ fors
}
int get(int i0){ // get sum of range [0,i0)
	int r=0; // add fors
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0,int i1){//sum of [i0,i1)
	return get(i1)-get(i0);
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	vv oc(n);
	vector<vv> pos(n);
	fore(i,0,n){
		cin>>a[i];
		a[i]--;
		oc[a[i]]++;
		pos[a[i]].pb(i);
	}
	vv sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+oc[i-1];
	// vv le(n);
	// fore(i,0,n)
	// for(le[i]=i-1;le[i]!=-1&&!(a[le[i]]<=a[i]);le[i]=le[le[i]]);
	
	vector<vector<ii>> qs(n);
	fore(i,0,q){
		ll l,r; cin>>l>>r; l--;
		qs[l].pb({r,i});
	}
	STree st(n);
	vv ans(q);
	for(ll val=n-1;val>=0;val--){
		auto &v=pos[val];
		for(auto i:v){
			while(1){
				auto j=st.query(0,i);
				if(st.a[j]<i)break;
				upd(a[j],-1);
				st.upd(j,-1);
			}
		}
		fore(idx,0,SZ(v)-1){
			ll l=v[idx],r=v[idx+1];
			upd(a[l],+1);
			st.upd(l,r);
		}
		for(auto [r,i]:qs[val]){
			auto &res=ans[i];
			res=sp[r]-sp[val];
			ll bars=get(r);
			res-=bars;
		}
	}
	for(auto i:ans)cout<<i<<"\n";
	return 0;
}
