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
const ll INF=2e9;
typedef ii node;
node oper(node a, node b){return {max(a.fst,b.fst),min(a.snd,b.snd)};}
node NEUT={0,INF};
// #define NEUT {0,INF}
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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		vector<pair<ii,ll>>b;
		vector<pair<ii,ll>>all;
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd; a[i].snd++;
			// ev.pb({a[i].fst,{1,i}});
			// ev.pb({a[i].snd,{-1,i}});
			all.pb({{a[i].snd,-a[i].fst},i});
			b.pb({{a[i].fst,-a[i].snd},i});
		}
		sort(ALL(all));
		sort(ALL(b));
		vv idx(n);
		fore(i,0,n){
			idx[all[i].snd]=i;
		}
		STree st(n);
		vv ans(n);
		for(auto [kjdfg,i]:b){
			auto rq=st.query(idx[i],n);
			ans[i]=rq==NEUT?0:rq.snd-rq.fst-(a[i].snd-a[i].fst);
			st.upd(idx[i],a[i]);
		}
		// iguales
		// imp(ans);
		for(ll i=n-1;i>0;i--){
			if(all[i].fst==all[i-1].fst)
				ans[all[i-1].snd]=ans[all[i].snd]=0;
		}
		for(auto i:ans){
			cout<<i<<"\n";
		}
	}
	return 0;
}
