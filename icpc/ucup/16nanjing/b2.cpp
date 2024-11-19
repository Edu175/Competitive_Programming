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
const ll MAXN=2e5+5;

struct node{
	ll c[2][2],mn=0,z;
	node(ll p, ll v):z(1){
		fore(i,0,2)fore(j,0,2)c[i][j]=0;
		if(v<2)c[v][p]=1;
	}
	void prnt(){
		cout<<"["<<z<<","<<mn<<"|";
		fore(i,0,2)fore(j,0,2)cout<<c[i][j]<<",";
		cout<<"] ";
	}
};
node oper(node a, node b){
	node c=a;
	c.z+=b.z;
	fore(i,0,2)fore(j,0,2){
		c.mn=min(c.mn,b.mn+a.z-2*a.c[i][j]);
		c.c[i][j]+=b.c[i][j];
		// c.mn=min(c.mn,c.z-2*c.c[i][j]);
	}
	return c;
}
node NEUT(0,2);
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};

int main(){FIN;
	// fore(i,0,2)fore(j,0,2)NEUT.c[i][j]=0;
	NEUT.z=0;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		STree st(n);
		fore(i,0,n)st.upd(i,{i&1,s[i]-'0'});
		vv dp(n+5);
		for(ll i=n-1;i>=0;i--){
			ll &res=dp[i];
			res=dp[i+1]+1;
			ll l=i/2,r=n/2,p=i&1;
			if(2*r+p>n)r--;
			while(l<=r){
				ll m=(l+r)/2;
				ll e=(2*m+p);
				cout<<l<<","<<r<<": "<<e<<"\n";
				if(st.query(i,e).mn<0)r=m-1;
				else l=m+1;
			}
			ll e=2*r+p;
			cout<<"\n";
			cout<<i<<": "<<e<<": ";
			st.query(i,e).prnt(); cout<<"\n";
			res=min(res,dp[e]);
			fore(j,i,n)if(j%2==p){
				cout<<j<<": ";st.query(i,j).prnt();cout<<"\n";
			}
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
