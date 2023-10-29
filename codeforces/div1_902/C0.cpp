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
const ll MAXN=2e5+5;

ll a[MAXN],c[MAXN],gr[MAXN];

ll cnt[MAXN];

void color(ll x, ll w){
	if(c[x])return;
	c[x]=w;
	if(w==1)color(a[x],2);
	else {
		cnt[a[x]]++;
		if(cnt[a[x]]==gr[a[x]])color(a[x],1);
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--,gr[a[i]]++;
	fore(x,0,n){
		if(!gr[x])color(x,1);
	}
	fore(x,0,n){
		if(c[x])continue;
		c[x]=1;
		ll w=2;
		for(ll y=a[x];y!=x;y=a[y],w=3-w)c[y]=w;
		if(w==2){
			cout<<"-1\n";
			return 0;
		}
	}
	vector<ll>res;
	fore(i,0,n)if(c[i]==1)res.pb(a[i]+1);
	cout<<SZ(res)<<"\n";
	imp(res);
	return 0;
}
