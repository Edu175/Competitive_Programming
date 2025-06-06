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
struct STree{
	int n,ty; node NEUT; vector<node>t;
	#define oper(a,b) ty?max(a,b):min(a,b)
	STree(int N, int ty):n(2<<__lg(N)),ty(ty),NEUT(ty?0:n),t(2*n+5,NEUT){}
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
		vv a(n),b(n),p(n,-1),pa(n,-1);
		fore(i,0,n)cin>>a[i],a[i]--,pa[a[i]]=i;
		fore(i,0,n){
			cin>>b[i],b[i]--;
			if(b[i]!=-1)p[b[i]]=i;
		}
		STree st0(n,0),st1(n,1);
		vv l(n),r(n); // [,)
		for(ll i=n-1;i>=0;i--){
			ll x=a[i];
			r[i]=min(n,st0.query(x,n));
			if(p[x]!=-1)st0.upd(x,p[x]);
		}
		ll fg=1;
		fore(i,0,n){
			ll x=a[i];
			l[i]=st1.query(0,x),fg&=l[i]<r[i];
			if(p[x]!=-1)st1.upd(x,p[x]);
		}
		if(!fg){
			cout<<"-1\n";
			continue;
		}
		priority_queue<ii>pq;
		vector<ll> h[n+1];
		fore(i,0,n)if(p[a[i]]==-1)h[l[i]].pb(i);
		fore(t,0,n){
			for(auto i:h[t])pq.push({-r[i],-i});
			if(b[t]==-1){
				if(!SZ(pq)){fg=0;break;}
				auto [dsj,i]=pq.top(); pq.pop(); i=-i;
				b[t]=a[i];
				fg&=t<r[i];
			}
		}
		fore(i,0,n)if(b[i]!=-1)p[b[i]]=i;
		fore(x,0,n){
			ll i=pa[x];
			fg&=l[i]<=p[x]&&p[x]<r[i];
		}
		if(!fg)cout<<"-1\n";
		else {
			for(auto i:b)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
