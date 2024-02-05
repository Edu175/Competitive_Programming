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

typedef ll node;
node oper(node a, node b){return a+b;}
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

ll fn(ll n){return n*(n-1)/2;}

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	vector<ll>a(n);
	set<ll>h;
	vector<ll>X(m),V(m);
	fore(i,0,m)cin>>X[i],X[i]--;
	fore(i,0,m)cin>>V[i];
	fore(i,0,m)h.insert(X[i]),a[X[i]]=V[i];
	STree st(n);
	fore(i,0,n){
		if(a[i]&&i<n-1){
			auto p=h.lower_bound(i+1);
			st.upd(i,a[i]*fn(*p-i));
		}
	}
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,v; cin>>x>>v; x--;
			auto p=h.lower_bound(x);
			ll l=*prev(p),r=*p;
			st.upd(l,a[l]*fn(x-l));
			st.upd(x,v*fn(r-x));
			a[x]=v;
			h.insert(x);
		}
		else {
			imp(h);
			ll s,e; cin>>s>>e; s--;
			ll l=*h.lower_bound(s),r=*prev(h.lower_bound(e+1));
			cout<<s<<","<<e<<" "<<l<<","<<r<<endl;
			ll res=st.query(l,r);
			if(l!=s){
				ll li=*prev(h.lower_bound(s));
				res+=a[li]*fn(l-s);
			}
			if(r!=e){
				ll ri=*h.lower_bound(e);
				res+=(fn(ri-r)-fn(ri-e))*a[r];
			}
			cout<<res<<"\n";
		}
		//fore(i,0,n)cout<<(ll)st.query(i,i+1)<<" ";;cout<<"\n";
	}
	return 0;
}
