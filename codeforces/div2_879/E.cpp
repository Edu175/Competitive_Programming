#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXV=5e6;

ll oper(ll a, ll b){
	ll res=lcm(a,b);
	if(res>=MAXV)res=MAXV;
	return res;
}
struct ST{
	ll n,K; vector<vector<ll>>st;
	ST(ll n):n(n),K(64-__builtin_clzll(n)),st(K,vector<ll>(1<<K)){}
	void init(vector<ll>a){
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n-(1<<k)+1)
			st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
	}
	ll query(ll s, ll e){
		ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ST st(n);
		st.init(a);
		vector<ll>b;
		fore(i,0,n){
			ll x=i;
			while(x<n){
				ll q=st.query(i,x+1);
				b.pb(q);
				ll l=x,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(q==st.query(i,m+1))l=m+1;
					else r=m-1;
				}
				x=l;
			}
		}
		vector<bool> vis(SZ(b)+5);
		for(auto i:b)if(i<SZ(vis))vis[i]=1;
		ll res=1;
		fore(i,1,SZ(vis))if(!vis[i]){res=i;break;}
		cout<<res<<"\n";
	}
	return 0;
}
