#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e15,MAXN=5e4+5;
#define oper min
#define NEUT INF

ll n,t;
ll a[MAXN];


struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

ll best (ll x){
	STree dp(n);
	dp.upd(n-1,0);
	for(int i=n-2;i>=0;i--){
		ll y=dp.query(i+1,min(n,i+x+1));
		dp.upd(i,a[i]+y);
	}
	// fore(i,0,n){
	// 	cout<<dp.query(i,i+1);
	// }
	return dp.query(0,1);
}

int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("journey.in","r",stdin);     freopen("journey.out","w",stdout);
	#endif
	cin>>n>>t;
	ll tarjetas[n-1];
	fore(i,0,n-1) cin>>tarjetas[i];
	a[0]=0;
	fore(i,1,n-1){
		cin>>a[i];
	}
	ll l=1;
	ll r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(best(m)+n-1>t) l=m+1;
		else r=m-1;
	}
	l-=3;
	while(l<1 || best(l)+n-1>t){
		l++;
	}
	// best(1);
	//cout<<best(2);
	ll b=INF;
	fore(i,l-1,n-1){
		b=min(b,tarjetas[i]);
	}
	cout<<b<<"\n";
	return 0;
}