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

ii msb(ll x, ll y){
	for(ll j=19;j>=0;j--){
		ll l=(x>>j)&1,r=(y>>j)&1;
		if(l!=r){
			if(l)return {0,1ll<<j};
			else return {1ll<<j,0};
		}
	}
	return {0,0};
}
const ll K=18;//K such that 2^k>n
ii oper(ii a, ii b){
	return {a.fst|b.fst,a.snd|b.snd};
}
ii st[K][1ll<<K];
void st_init(vector<ii> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ii st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ll>a(n);
		vector<ii>b(n,{0,0});
		fore(i,0,n)cin>>a[i];
		fore(i,1,n)b[i]=msb(a[i-1],a[i]);
		st_init(b);
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll p=l,last=0;
			ll res=0;
			while(p<r){
				res++;
				ii h={0,0};
				if(p>l)h=msb(a[p-1]^last,a[p]);
				ll s=p+1,e=n-1;
				while(s<=e){
					ll m=(s+e)/2;
					ii now=oper(h,st_query(p+1,m+1));
					if(now.fst&now.snd)e=m-1;
					else s=m+1;
				}
				p=e;
				last=oper(h,st_query(p+1,e+1)).fst;
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
