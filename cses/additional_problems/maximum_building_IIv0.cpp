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
	STree(int N):n(N+1),t(2*n+5,NEUT){}
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
	void upd(ll l, ll r, node v){
		upd(l,v);
		upd(r,-v);
	}
	node query(ll p){return query(0,p+1);}
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<string> a(n,string(m,'.'));
	fore(i,0,n)cin>>a[i];
	vector<array<ll,3>> h[n+3];
	auto add=[&](ll i0, ll i1, ll j0, ll j1){
		cout<<"add "<<i0<<","<<i1<<" "<<j0<<","<<j1<<"\n";
		h[i0].pb({j0,j1,1});
		h[i1].pb({j0,j1,-1});
	};
	auto fila=[&](vv a){ // {heights}
		cout<<"fila "; imp(a)
		ll n=SZ(a);
		set<ll>st={-1,n};
		vector<ii> sa;
		fore(i,0,n)sa.pb({a[i],i});
		sort(ALL(sa));
		for(auto [x,i]:sa){
			ll l=0,r=0;
			ll le=*prev(st.lower_bound(i));
			ll ri=*st.lower_bound(i);
			if(le!=-1)l=a[le];
			if(ri!=n)r=a[ri];
			add(max(l,r)+1,x+1,1,ri-le);
			st.insert(i);
		}
	};
	
	vv v(m);
	fore(i,0,n){
		fore(j,0,m){
			v[j]++;
			if(a[i][j]=='*')v[j]=0;
		}
		fila(v);
	}
	
	STree st(m+1);
	vector<vv> ans(n+1,vv(m+1));
	fore(i,0,n+1){
		for(auto [l,r,v]:h[i])st.upd(l,r,v);
		fore(j,1,m+1)ans[i][j]=st.query(j);
	}
	fore(i,1,n+1)fore(j,1,m+1)cout<<ans[i][j]<<" \n"[j==m];
	return 0;
}
