#include "gondola.h"
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

void rotate(vector<ll>&a, ll x){
	rotate(a.begin(),a.begin()+x,a.end());
}

int valid(int n, int A[]){
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	set<ll>st;
	fore(i,0,n)st.insert(a[i]);
	if(SZ(st)<n)return 0;
	ll done=0;
	fore(i,0,n)if(!done&&a[i]<n){
		ll v=a[i];
		rotate(a,i);
		rotate(a,(n-v)%n),done=1;
	}
	if(!done)return 1;
	ll flag=1;
	fore(i,0,n){
		ll fi=a[i]>=n||a[i]==i;
		flag&=fi;
	}
	return flag;
}
int replacement(int n, int A[], int ret[]){
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	set<ll>st;
	fore(i,0,n)st.insert(a[i]);
	assert(SZ(st)==n);
	ll done=0;
	// imp(a);
	fore(i,0,n)if(!done&&a[i]<n){
		ll v=a[i];
		rotate(a,i);
		rotate(a,(n-v)%n),done=1;
	}
	// imp(a);
	vector<ii>b;
	fore(i,0,n)if(a[i]>=n)b.pb({a[i],i});
	fore(i,0,n)a[i]=i;
	sort(ALL(b));
	ll p=-1;
	vector<ll>res;
	if(!SZ(b))return 0;
	// for(auto [c,v]:b)cout<<c<<","<<v<<" ";;cout<<"\n";
	fore(k,n,b.back().fst+1){
		// cout<<k<<": "<<p<<endl;
		ll i=b[p+1].snd;
		res.pb(a[i]);
		a[i]=k;
		if(b[p+1].fst==k)p++;
	}
	fore(i,0,SZ(res))ret[i]=res[i]+1;
	return SZ(res);
}
const ll MOD=1e9+9;
// ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
// ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b),e>>=1;
	}
	return res;
}
int countReplacement(int n, int A[]){
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	if(!valid(n,A))return 0;
	ll done=0;
	// imp(a);
	fore(i,0,n)if(!done&&a[i]<n){
		ll v=a[i];
		rotate(a,i);
		rotate(a,(n-v)%n),done=1;
	}
	// imp(a);
	vector<ll>b;
	fore(i,0,n)if(a[i]>=n)b.pb(a[i]);
	sort(ALL(b));
	// if(!SZ(b))return 1;
	ll res=1;
	fore(i,0,SZ(b)){
		ll dif=b[i]-(i?b[i-1]:n-1)-1;
		res=mul(res,fpow(SZ(b)-i,dif));
	}
	if(!done)res=mul(res,n);
	return res;
}

