#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
const ll MAXN=305;
ll a[MAXN];
ll n;
int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	vector<ll>b(k),vis(n),s;
	vector<pair<ll,ii>>v; ll u=0;
	fore(i,0,k){
		cin>>b[i],b[i]--; vis[b[i]]=1;
		if(b[i]-u)v.pb({b[i]-u,i});
		u=b[i];
	}
	ll res=0,sum=0;
	fore(i,0,n-1)res+=max(a[i],a[i+1]);
	fore(i,0,n){
		if(!vis[i])s.pb(a[i]),sum+=a[i];
	}
	sort(ALL(s));
	sort(ALL(v));
	do{
		ll p=0;
		for(auto [q,i]:v){
			ll l=b[i],r=b[i]+1,mn=s[p],mx=s[p+q-1];
			
		}
	}
	while(next_permutatuion(ALL(v)));
	fore(i,0,n)if(!is[i])s.pb(i);
	cout<<SA()<<"\n";
	cout<<r<<"\n";
	fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
	return 0;
}
