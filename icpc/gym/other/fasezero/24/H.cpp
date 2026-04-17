#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=115;
ll is[MAXN];

int main(){FIN;
	fore(x,2,MAXN){
		is[x]=1;
		for(ll i=2;i*i<=x;i++)if(x%i==0)is[x]=0;
	}
	ii ans[MAXN];
	fore(n,2,MAXN)if(n&1){
		ll x=-1,y=-1;
		fore(i,1,n)if(!is[i]&&!is[n-i]&&i<n-i){
			if(x==-1||abs(i-(n-i))<abs(x-y))x=i,y=n-i;
		}
		ans[n]={x,y};
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		while(n>=MAXN);
		ll x=ans[n].fst,y=ans[n].snd;
		if(x==-1)cout<<x<<"\n";
		else cout<<x<<" "<<y<<"\n";
	}
	return 0;
}
