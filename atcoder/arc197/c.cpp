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
const ll MAXN=1e7;

bitset<MAXN>vis;
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int N):n(2<<__lg(N)),t(2*n+5,NEUT){}
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
	ll find(ll k, ll s, ll e, ll x){
		if(s+1==e){
			if(t[k]>=x)return s;
			assert(0);
			return n; //o s+1?
		}
		ll m=(s+e)/2;
		if(t[2*k]>=x)return find(2*k,s,m,x);
		return find(2*k+1,m,e,x-t[2*k]);
	}
	ll find(ll x){return find(1,0,n,x);} //lowerbound on sum prefixes
	
};
int main(){FIN;
	STree st(MAXN);
	fore(i,1,MAXN)st.upd(i,1);
	ll q; cin>>q;
	while(q--){
		ll m,p; cin>>m>>p; //p--;
		if(m<MAXN&&!vis[m]){
			for(ll j=m;j<MAXN;j+=m)if(!vis[j])
				vis[j]=1,st.upd(j,0);
		}
		// fore(i,0,p*2)cout<<st.query(i,i+1)<<" ";;cout<<"\n";
		cout<<st.find(p)<<"\n";
	}
	return 0;
}
