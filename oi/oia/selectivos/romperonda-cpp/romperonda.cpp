#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n";
using namespace std;
typedef int ll;
const ll MAXN=6e3+5,MAXK=55,MAXS=16,INF=1e9;

ll n,K,a[MAXN];
ll dp1[MAXN][MAXS][MAXK];
ll f1(ll i,ll s, ll k){
	return dp1[i][s][k];
}
ll dp0[MAXN][MAXS][MAXK][MAXS];
ll f0(ll i,ll s, ll k, ll p){
	return dp0[i][s][k][p];
}
vector<int> romperonda(vector<int> &ronda, int k) {
	K=k;
	n=SZ(ronda);
	fore(i,0,n)a[i]=ronda[i];
	for(ll i=n;i>=0;i--)fore(s,0,16)fore(k,0,K+1){
		ll &res=dp1[i][s][k];
		if(k==K){res=-INF;continue;}
		if(i==n){
			if(k==K-1)res=s*s;
			else res=-INF;
			continue;
		}
		res=max(f1(i+1,(s+a[i])%16,k),s*s+f1(i+1,a[i]%16,k+1));
	}
	for(ll i=n;i>=0;i--)fore(s,0,16)fore(k,0,K+2)fore(p,0,16){
		ll &res=dp0[i][s][k][p];
		if(k>K){res=-INF;continue;}
		if(i==n){
			if(k==K)res=((s+p)%16)*((s+p)%16);
			else if(k==K-1)res=s*s+p*p;
			else res=-INF;
			continue;
		}
		res=max(f0(i+1,(s+a[i])%16,k,p),(k>0)*s*s+f0(i+1,a[i]%16,k+1,(!k?s:p)));
	}
	ll res0=f0(1,a[0]%16,0,0),res1=(a[0]%16)*(a[0]%16)+f1(2,a[1]%16,1);
	vector<int>ret={(int)res0,(int)res1};
	return ret;
}
