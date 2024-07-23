#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;
const ll K=19;

ll ST[K][MAXN];
#define oper min
void st_init(vector<ll>&a){
	ll n=SZ(a);
	fore(i,0,n)ST[0][i]=a[i];
	fore(k,1,K)fore(i,0,n)if(i+(1ll<<k)<=n)
		ST[k][i]=oper(ST[k-1][i],ST[k-1][i+(1ll<<(k-1))]);
}
ll st_query(ll s, ll e){
	ll k=(63-__builtin_clzll(e-s));
	return oper(ST[k][s],ST[k][e-(1ll<<k)]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>fb(n,-1);
		// for(ll i=n-1;i>=0;i--)
		// 	for(fs[i]=i+1;fs[i]<n&&a[i]<=a[fs[i]];fs[i]=fs[fs[i]]);
		fore(i,0,n){
			for(fb[i]=i-1;fb[i]>=0&&a[i]>=a[fb[i]];fb[i]=fb[fb[i]]);
		}
		vector<ll> fr(n);
		for(ll i=n-1;i>=0;i--){
			for(fr[i]=i+1;fr[i]<n&&a[i]>a[fr[i]];fr[i]=fr[fr[i]]);
		}
		vector<ll>fs(n);
		st_init(a);
		fore(i,0,n){
			ll l=fr[i],r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(st_query(fr[i],m+1)<a[i])r=m-1;
				else l=m+1;
			}
			fs[i]=l;
		}
		ll no=0,res=n*(n+1)*(n+2)/6;
		fore(i,0,n){
			ll ls=fb[i]+1,le=i+1,rs=fr[i],re=fs[i];
			// cout<<i<<": "<<ls<<","<<le<<" "<<rs<<","<<re<<" = "<<(le-ls)*(re-rs)<<"\n";
			no+=(le-ls)*(re-rs);
		}
		no+=n*(n+1)/2;
		// cout<<n<<": "<<res<<" "<<no<<"\n";
		cout<<res-no<<"\n";
	}
	return 0;
}