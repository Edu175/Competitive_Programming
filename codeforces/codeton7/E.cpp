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
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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
		vv a(2*n);
		// vv pos(n);
		fore(i,0,n)cin>>a[i],a[i]--;//,pos[a[i]]=i;
		fore(i,n,SZ(a))a[i]=a[i-n];
		STree st(2*n);
		vv ans(n);
		for(ll i=2*n-1;i>=0;i--){
			ll x=a[i];
			ll r=x;
			if(r<i)r+=n;
			// cout<<i<<" -> "<<r<<"\n";
			if(i<n){
				assert(r>=i);
				ll &res=ans[x];
				res=r-i;
				res-=st.query(i,r);
				// cout<<"ans "<<x<<": "<<res<<"\n";
			}
			if(r>=i){
				// cout<<"added "<<r<<"\n";
				st.upd(r,1);
			}
		}
		imp(ans)
	}
	return 0;
}
