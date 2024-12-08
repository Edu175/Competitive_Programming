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
const ll K=19;//K such that 2^k>n
#define oper(a,b) a|b
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
#define oper2 max
ll st2[K][1ll<<K];
void st2_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st2[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st2[k][i]=oper2(st2[k-1][i],st2[k-1][i+(1ll<<(k-1))]);
}
ll st2_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper2(st2[k][s],st2[k][e-(1<<k)]);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		st_init(a);
		st2_init(a);
		ll res=0;
		fore(i,0,n){
			ll p=i+1;
			while(p<n){
				ll l=p,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(st_query(i,m+1)==st_query(i,p+1))l=m+1;
					else r=m-1;
				}
				res=max(res,
				a[i]+st_query(i,p+1)+st2_query(p,l));
				p=l;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
