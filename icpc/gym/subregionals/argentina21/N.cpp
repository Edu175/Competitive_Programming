#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
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
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv ps(q),ls(q);
	vector<array<ll,4>> qs(q);
	fore(i,0,q){
		ll a,p,f; cin>>a>>p>>f; a--;
		qs[i]={p,a,f,i};
		ps[i]=p;
		ls[i]=a;
	}
	sort(ALL(qs)); reverse(ALL(qs));
	vector<ii> sa; fore(i,0,n)sa.pb({a[i],i});
	sort(ALL(sa)); reverse(ALL(sa));
	STree st(n);
	ll po=0;
	vv ans(q);
	for(auto [val,i]:sa){
		while(po<q&&qs[po][0]>val){
			auto [asd,l,z,idx]=qs[po++];
			ans[idx]=st.query(l+1,l+z+1);
		}
		st.upd(i,1);
	}
	while(po<q){
		auto [asd,l,z,idx]=qs[po++];
		ans[idx]=st.query(l+1,l+z+1);
	}
	fore(i,0,q){
		ll res=ans[i];
		if(ps[i]<=a[ls[i]])res=0;
		cout<<res<<"\n";
	}
	return 0;
}
