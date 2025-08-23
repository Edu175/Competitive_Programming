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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll MAXN=5e4+5;
typedef bitset<MAXN> biset;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n),p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	biset mk;
	vector<biset> mks(n);
	fore(i,0,n)mk[i]=1;
	fore(v,0,n){
		ll i=p[v];
		mk[i]=0;
		mks[i]=mk>>i;
	}
	vector<biset> suf(n);
	for(ll i=n-1;i>=0;i--){
		if(i%k==0)mk=mks[i];
		else mk&=mks[i];
		suf[i]=mk;
	}
	mk.reset();
	ll res=0;
	fore(i,0,n){
		if(i%k==0)mk=mks[i];
		else mk&=mks[i];
		ll l=i-k+1;
		if(l<0)continue;
		ll cur=(mk&suf[l]).count();
		res+=cur;
	}
	cout<<res<<"\n";
	return 0;
}
