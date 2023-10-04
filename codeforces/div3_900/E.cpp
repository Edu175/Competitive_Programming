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
const ll K=18;//K such that 2^k>n
ll oper(ll a, ll b){return a&b;}
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(ll s, ll e){
	ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		st_init(a);
		ll q; cin>>q;
		while(q--){
			ll s,k; cin>>s>>k; s--;
			ll l=s+1,r=n;
			while(l<=r){
				ll m=(l+r)/2;
				if(st_query(s,m)<k)r=m-1;
				else l=m+1;
			}
			if(r==s)cout<<"-1 ";
			else cout<<r<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
