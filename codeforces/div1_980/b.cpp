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
const ll INF=1e15;
typedef ll node;
#define oper min
#define NEUT INF
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
// la puta madreee lei bj<=bi
// 45 minutos al pedo

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i],b[i]--;
		vv sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		STree st(n);
		ll res=a[0];
		for(ll i=n-1;i>=0;i--){
			ll j=b[i];
			res=sp[n]-sp[j+1];
			res=min(res,st.query(i+1,j+1));
			res+=a[i];
			st.upd(i,res);
		}
		res=sp[n]-res;
		res=max(res,a[0]);
		cout<<res<<"\n";
	}
	return 0;
}
