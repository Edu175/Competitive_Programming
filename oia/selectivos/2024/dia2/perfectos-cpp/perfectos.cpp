#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdkjg:v)cout<<fdkjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXV=1e7+6;

ll cr[MAXV];
map<ll,ll>h;
ll rnd(){
	return (ll(rand())<<30)^rand();
}
ll val(ll x){
	if(h.count(x))return h[x];
	return h[x]=rnd();
}
ll fact(ll x){
	ll h=0;
//	cout<<"fact "<<x<<": ";
	while(x>1){
		ll y=cr[x];
//		cout<<y<<" ";
		h^=val(y);
		x/=y;
	}
//	cout<<"= "<<h<<"\n";
	return h;
}
long long perfectos(vector<int> &a) {
	srand(175);
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]==-1)for(ll j=i;j<MAXV;j+=i)cr[j]=i;
	ll n=SZ(a);
	vector<ll> xp(2*n+1);
	map<ll,ll>c;
	c[0]=1;
	ll res=0;
	fore(i,1,2*n){
		ll y=i-n;
		if(y>=0)c[xp[y]]--;
		xp[i]=xp[i-1]^fact(a[(i-1)%n]);
		res+=c[xp[i]];
		if(i<n)c[xp[i]]++;
	}
	res+=xp[n]==0;
	return res;
}
