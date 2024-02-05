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
const ll INF=2e5+5;

//typedef ll ll;
ll oper(ll a, ll b, ll ty){
	if(ty)return max(a,b);
	else return min(a,b);
}
ll NEUT(ll ty){
	if(ty)return -1;
	else return INF;
}
struct STree{
	int n,ty; vector<ll>t;
	STree(int n, int ty):n(n),ty(ty),t(2*n+5,NEUT(ty)){}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1],ty);
	}
	ll query(int l, int r){
		ll res=NEUT(ty);
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++],ty);
			if(r&1)res=oper(res,t[--r],ty);
		}
		return res;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),b(n);
		vector<ll>pos[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--,pos[b[i]].pb(i);
		STree sa(n,1),sb(n,0);
		fore(i,0,n)sa.upd(i,a[i]),sb.upd(i,b[i]);
		ll flag=1;
		fore(v,0,n){
			ll Ll=-1,Lr=-1;
			for(auto i:pos[v]){
				if(Ll<=i&&i<=Lr)continue;
				ll s=0,e=i;
				while(s<=e){
					ll m=(s+e)/2;
					if(sa.query(m,i)<=v&&sb.query(m,i)>=v)e=m-1;
					else s=m+1;
				}
				ll l=s;
				s=i,e=n-1;
				while(s<=e){
					ll m=(s+e)/2;
					if(sa.query(i,m+1)<=v&&sb.query(i,m+1)>=v)s=m+1;
					else e=m-1;
				}
				ll r=e;
				if(sa.query(l,r+1)!=v)flag=0;
				//cout<<v<<" "<<i<<": "<<l<<" "<<r<<": "<<hay.query(l,r+1)<<"\n";
				Ll=l,Lr=r;
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
