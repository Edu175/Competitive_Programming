#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct STree{ // range upd suma, query puntual
	ll n; vector<ll> t;
	STree(ll N):n(N+3),t(2*n+5,0){}
	void __upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll __query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
	void upd(ll l, ll r, ll v){__upd(l,v);__upd(r,-v);}
	ll query(ll p){return __query(0,p+1);}
};

vector<vv> rectangulos(ll n, ll m, vector<array<ll,4>> &u){
	// of an nxm grid, add upds u given by i0,j0,i1,j1,+1
	vector<vv> res(n,vv(m));
	vector<vector<array<ll,3>>> h(n+1);
	for(auto& [i0,j0,i1,j1]:u){
		h[i0].pb({j0,j1,1});
		h[i1].pb({j0,j1,-1});
	}
	STree st(m);
	fore(i,0,n){
		for(auto& [j0,j1,v]:h[i])st.upd(j0,j1,v);
		fore(j,0,m)res[i][j]=st.query(j);
	}
	return res;
}

vector<vv> sweep(ll n, ll m, vector<array<ll,3>> &u){
	vector<vv> res(n,vv(m));
	vector<vv> h(n+1,vv(m));
	for(auto& [i0,i1,w]:u){
		assert(i0<=n&&i1<=n);
		assert(w<m);
		h[i0][w]++;
		h[i1][w]--;
	}
	vv dp(m+1);
	fore(i,0,n){
		ll q=0,s=0;
		for(ll j=m-1;j>=0;j--){
			q+=h[i][j];
			s+=q;
			dp[j]+=s;
			res[i][j]=dp[j];
		}
	}
	return res;
}

int main(){
    JET
	ll n,m,k,q; cin>>n>>m>>k>>q;
	// n++,m++;
	vector<array<ll,4>> u;
	fore(_,0,k){
		ll i0,j0,i1,j1; cin>>i0>>i1>>j0>>j1;
		u.pb({i0,j0,i1,j1});
	}
	auto a=rectangulos(n,m,u);
	// cout<<"a:\n";
	// fore(i,0,n){
	// 	fore(j,0,m)cout<<a[i][j]<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n";
	
	vv dp(m);
	vector<array<ll,3>> upd;
	for(ll i=n-1;i>=0;i--){
		fore(j,0,m){
			dp[j]++;
			if(a[i][j])dp[j]=0;
		}
		set<ll> st={-1,m};
		vector<ii> sd;
		fore(j,0,m)sd.pb({dp[j],j});
		sort(ALL(sd));
		auto acc=[&](ll i){return i<0||i>=m?-1:dp[i];};
		for(auto [v,j]:sd){
			auto it=st.insert(j).fst;
			ll l=*prev(it),r=*next(it);
			ll i0=max(acc(l),acc(r))+1,i1=dp[j]+1;
			ll w=r-l;
			upd.pb({i0,i1,w-1});
		}
	}
	auto res=sweep(n+1,m+1,upd);
	// cout<<"res:\n";
	// fore(i,1,n+1){
	// 	fore(j,1,m+1)cout<<res[i][j]<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n";
	while(q--){
		ll i,j; cin>>i>>j;
		cout<<res[i][j]<<"\n";
	}
    return 0;
}