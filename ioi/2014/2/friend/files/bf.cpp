#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
ll g[MAXN],c[MAXN];
ll n;
int findSample(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	fore(i,1,n){
		if(t[i]%2==0)g[i]|=1ll<<p[i];
		if(t[i]>0)g[i]|=g[p[i]];
		fore(j,0,n)if(g[i]>>j&1)g[j]|=1ll<<i;
	}
	// fore(i,0,n)fore(j,0,n){
	// 	if(g[i]>>j&1)g[j]|=1ll<<i;
	// }
	fore(i,0,n){
		cerr<<i<<": ";
		fore(j,0,n)cerr<<(g[i]>>j&1);
		cerr<<"\n";
	}
	ll res=0;
	fore(mk,0,1ll<<n){
		ll sum=0,flag=1;
		fore(i,0,n)if(mk>>i&1)sum+=c[i],flag&=!(mk&g[i]);
		if(flag)res=max(res,sum);
	}
	return res;
}
