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
const ll MAXB=35;

ii cnt(ll x){
	ii res={-1,-1};
	for(ll i=MAXB-1;i>=0;i--){
		if(res.fst==-1){
			if(x&(1ll<<i))res.fst=i+1;
		}
		else if(res.snd==-1){
			if(!(x&(1ll<<i)))res.snd=i+1;
		}
		else if(x&(1ll<<i))return {-1,-1};
	}
	if(res.snd==-1)res.snd=0;
	if(res.fst==-1)res.fst=0;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		ll sum=0;
		fore(i,0,n)cin>>a[i],sum+=a[i];
		if(sum%n){
			cout<<"No\n";
			continue;
		}
		ll e=sum/n;
		vector<ll>in,out;
		ll h[MAXB]={};
		ll res=1;
		fore(i,0,n){
			//if(e==a[i])continue;
			ii p=cnt(abs(e-a[i]));
			//cout<<i<<": "<<p.fst<<","<<p.snd<<"\n";
			if(p.fst==-1){
				res=0;
				continue;
			}
			if(a[i]>e)h[p.fst]++,h[p.snd]--;//out.pb(p.fst),in.pb(p.snd);
			if(a[i]<e)h[p.fst]--,h[p.snd]++;//in.pb(p.fst),out.pb(p.snd);
		}
		fore(i,0,MAXB)if(h[i]!=0)res=0;
		if(res)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
