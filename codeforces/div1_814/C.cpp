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
#define oper max
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(){}
	STree(int n):n(n),t(2*n+5,NEUT){}
	void init(vector<node> &a){
		fore(i,0,n)t[n+i]=a[i];
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
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
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv ds;
		fore(i,1,n)if(n%i==0)ds.pb(i);
		ll m=SZ(ds);
		vector<STree> st(m);
		vector<priority_queue<ii>> pq(m);
		ll res=0;
		fore(i,0,m){
			ll d=ds[i];
			vv sum(d);
			fore(j,0,n)sum[j%d]+=a[j];
			st[i]=STree(d);
			st[i].init(sum);
			res=max(res,d*st[i].query(0,d));
		}
		cout<<res<<"\n";
		while(q--){
			ll j,x; cin>>j>>x; j--;
			ll res=0;
			fore(i,0,m){
				ll d=ds[i];
				ll r=j%d;
				st[i].upd(r,x-a[j]);
				res=max(res,d*st[i].query(0,d));
			}
			a[j]=x;
			cout<<res<<"\n";
		}
	}
	return 0;
}
