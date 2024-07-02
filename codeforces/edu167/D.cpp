#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e11;
typedef ll node;
#define oper min
#define NEUT INF
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=min(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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
const ll MAXV=1e6+5;

int main(){FIN;
	ll n,m; cin>>n>>m;
	STree st(MAXV);
	vector<ll>a(n),b(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n){
		st.upd(a[i],a[i]-b[i]);
	}
	vector<ll>oc(MAXV);
	ll res=0;
	ll z=st.query(0,MAXV);
	fore(i,0,m){
		ll x; cin>>x;
		ll k=0;
		if(x>=MAXV)k=(x-MAXV)/z+1;
		res+=k;
		oc[x-k*z]++;
	}
	for(ll i=MAXV-1;i>=0;i--){
		ll z=st.query(0,i+1);
		if(z>=INF)continue;
		res+=oc[i];
		oc[i-z]+=oc[i];
	}
	cout<<res*2<<"\n";
	return 0;
}