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
		ll n,q; cin>>n>>q;
		set<ll> unos;
		STree st(n);
		vv a(n);
		fore(i,0,n){
			cin>>a[i];
			if(a[i]==1)unos.insert(i);
			st.upd(i,a[i]);
		}
		while(q--){
			ll ty; cin>>ty;
			if(ty==1){
				ll s; cin>>s;
				ll sum=0;
				if(SZ(unos)){
					ll l=*unos.begin();
					ll r=*unos.rbegin();
					sum=max(st.query(l,n),st.query(0,r+1));
				}
				ll good=0;
				if(s<=sum||sum%2==s%2)good=1;
				if(s>st.query(0,n))good=0;
				if(good)cout<<"YES\n";
				else cout<<"NO\n";
			}
			else {
				ll i,v; cin>>i>>v; i--;
				st.upd(i,v);
				if(v==1)unos.insert(i);
				else unos.erase(i);
			}
		}
	}
	return 0;
}
