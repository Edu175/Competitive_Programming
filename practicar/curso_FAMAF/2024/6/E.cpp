#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef ii node;
node oper(node a, node b){
	return {min(a.fst,b.fst),max(a.snd,b.snd)};
}
ii NEUT={2e6+5,-2e6-5};
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
		string s; cin>>s;
		n++;
		vector<ll>a(n);
		STree st(n);
		fore(i,1,n){
			a[i]=a[i-1]+(s[i-1]=='+'?1:-1);
		}
		fore(i,0,n)st.upd(i,{a[i],a[i]});
		// imp(a);
		while(q--){
			ll l,r; cin>>l>>r; r++;
			ii rq=st.query(0,l);
			ii b=st.query(r,n);
			ll s=a[r-1]-a[l-1];
			b.fst-=s,b.snd-=s;
			rq=oper(rq,b);
			// if(rq==NEUT)cout
			// cout<<"saldo "<<s<<"\n";
			// cout<<l<<","<<r<<": "<<rq.fst<<","<<rq.snd<<" = ";
			cout<<rq.snd-rq.fst+1<<"\n";
		}

	}
	return 0;
}