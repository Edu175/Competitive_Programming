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

ll fn(ll n){return n*(n-1)/2;} // )
ll fn(ll l, ll r){return fn(r)-fn(l);} // [,)

int main(){FIN;
	ll n; cin>>n;
	vv a(n),p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	STree st(n);
	fore(i,0,n)st.upd(i,1);
	ll res=0;
	for(ll x=n-1;x>=0;x--){
		ll pos=p[x];
		ll c=st.query(pos+1,n);
		
		ll cant=pos-st.query(0,pos);
		ll s=pos+1-cant;
		
		ll cur=fn(s,s+c);
		res+=cur;
		// cout<<x<<" "<<pos<<": "<<c<<" "<<cur<<"\n";
		st.upd(pos,0);
	}
	cout<<res<<"\n";
	return 0;
}
