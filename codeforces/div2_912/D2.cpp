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
const ll MAXN=1e6+5;

ll a[MAXN];
ll B=60,n,k;

bool on(ll x, ll j){return !!(x&(1ll<<j));}

bool can(ll x){
	vector<ll>ai(n);
	fore(i,0,n)ai[i]=a[i];
	ll ops=0;
	fore(i,0,n){
		for(ll j=B-1;j>=0;j--){
			if(!on(x,j)&&on(ai[i],j))ai[i]-=1ll<<j;
			else if(on(x,j)&&!on(ai[i],j)){
				ops+=x-ai[i];
				break;
			}
		}
		if(ops>k)return 0;
	}
	return ops<=k;
}

int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n)cin>>a[i];
	while(q--){
		cin>>k;
		ll res=0;
		for(ll j=B-1;j>=0;j--){
			if(can(res|(1ll<<j)))res|=1ll<<j;
		}
		cout<<res<<"\n";
	}
	return 0;
}
