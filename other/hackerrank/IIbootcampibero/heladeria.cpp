#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

typedef ll node;
#define oper max
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
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
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	STree st(n);
	fore(i,0,n)cin>>a[i],st.upd(i,a[i]);
	while(q--){
		ll ty,u,v; cin>>ty>>u>>v; u--;
		if(ty==1){
			st.upd(u,v);
		}
		else if(ty==2){
			cout<<st.query(u,v)<<"\n";
		}
		else {
			ll l=u,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(st.query(u,m+1)>=v)r=m-1;
				else l=m+1;
			}
			cout<<l+1<<"\n";
		}
	}
	return 0;
}
