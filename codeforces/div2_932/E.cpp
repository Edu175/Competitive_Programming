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
typedef ii node;
#define NEUT {0,0}
node oper(node a, node b){
	node c=NEUT;
	c.fst=a.fst|b.fst;
	c.snd=a.snd|b.snd|(a.fst&b.fst);
	return c;
}
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
ll msb(ll x){
	if(!x)return -1;
	return 63-__builtin_clzll(x); 
}
bool on(ll x, ll j){return (x>>j)&1;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		vector<ll>b(n);
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			ll p=msb(a[i].fst^a[i].snd);
			if(p==-1)b[i]=a[i].fst,a[i].fst=a[i].snd=0;
			else {
				b[i]=a[i].fst&~((2ll<<p)-1);
				a[i].fst&=(2ll<<p)-1;
				a[i].snd&=(2ll<<p)-1;
			}
		}
		STree st(n),ors(n);
		fore(i,0,n)st.upd(i,{a[i].snd,0}),ors.upd(i,{b[i],0});
		ll q; cin>>q;
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll x=ors.query(l,r).fst;
			ii h=st.query(l,r);
			//cout<<"\n"<<x<<" "<<h.fst<<","<<h.snd<<"\n";
			for(ll j=35;j>=0;j--){
				if(!on(h.fst,j))continue;
				if(on(h.snd,j)||on(x,j)){
					x|=(2ll<<j)-1;
					break;
				}
				x|=1ll<<j;
			}
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
