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
const ll INF=1e10;
#define oper max
#define NEUT -1
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
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		vv v[n];
		fore(i,0,n)cin>>b[i],b[i]--,v[b[i]].pb(i);
		STree st(n);
		fore(i,0,n)if(SZ(v[i])){
			sort(ALL(v[i])),st.upd(i,v[i].back());
		}
		// fore(i,0,n)st.upd(b[i],i);
		ll p=0,res=0;
		set<ll>s;
		fore(i,0,n)s.insert(i);
		while(1){
			ll pi=st.query(0,b[p]+1);
			cout<<p<<": ";
			if(pi>p)p=pi,cout<<"skip\n";
			else {
				cout<<"submit\n";
				res+=a[p];
				auto &u=v[b[p]];
				u.pop_back();
				st.upd(b[p],SZ(u)?u.back():NEUT);
				s.erase(p);
				auto it=s.lower_bound(p);
				if(it==s.begin())break;
				p=*(--it);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
