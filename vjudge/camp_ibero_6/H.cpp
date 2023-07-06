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

ll oper(ll a, ll b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<ll>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll _=0,n;
	while(cin>>n){
		cout<<"Case #"<<++_<<":\n";
		ll a[n];
		fore(i,0,n)cin>>a[i];
		STree st(n);
		fore(i,0,n)st.upd(i,a[i]);
		set<ll>pos;
		fore(i,0,n)if(a[i]!=1)pos.insert(i);
		ll q; cin>>q;
		while(q--){
			ll ty; cin>>ty;
			if(!ty){
				ll l,r; cin>>l>>r; l--;
				vector<ll>del;
				for(auto i=pos.lower_bound(l);i!=pos.end()&&*i<r;i++){
					ll x=sqrt(a[*i]);
					a[*i]=x;
					st.upd(*i,x);
					if(x==1)del.pb(*i);
				}
				for(auto i:del)pos.erase(i);
			}
			else {
				ll l,r; cin>>l>>r; l--;
				cout<<st.query(l,r)<<"\n";
			}
		}
		cout<<"\n";
	}
	return 0;
}
