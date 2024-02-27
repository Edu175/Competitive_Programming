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
const ll MAXV=2e6+5,C=1e6;
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
struct event{
	ll t,l,r;
};
bool operator<(event a, event b){return a.t<b.t;}
int main(){FIN;
	ll n; cin>>n;
	vector<event>ev[MAXV];
	fore(i,0,n){
		vector<ll>a(4);
		fore(i,0,4)cin>>a[i],a[i]+=C;
		if(a[1]==a[3]){
			ev[a[0]].pb(event({0,a[1],-1}));
			ev[a[2]].pb(event({1,a[1],-1}));
		}
		else {
			ev[a[0]].pb(event({2,a[1],a[3]}));
		}
	}
	ll res=0;
	STree st(MAXV);
	fore(v,0,MAXV){
		sort(ALL(ev[v]));
		for(auto x:ev[v]){
			if(x.t==0)st.upd(x.l,1);
			if(x.t==1)st.upd(x.l,-1);
			if(x.t==2){
				res+=st.query(x.l,x.r);
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}
