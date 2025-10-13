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

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n){
		cin>>a[i];
		if(a[i]>0)a[i]--;
	}
	ll pre=0;
	while(pre<n && (a[pre]==-1||a[pre]==pre+1))pre++;
	
	ll suf=n-1;
	while(suf>=0 && (a[suf]==-1||a[suf]==suf-1))suf--;

	ll res=0;
	fore(i,0,n){
		ll good= i<=pre && i>=suf;
		if(!good)continue;
		ll cur=0;
		if(a[i]==-1)cur=n-1+(!i);
		else cur=a[i]!=i-1;
		res+=cur;
	}
	cout<<res%998244353<<"\n";
	return 0;
}
