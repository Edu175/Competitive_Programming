#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vv> mat;

ll get_ty(const vv &r){
	ll n=SZ(r);
	if(count(ALL(r),0)==n)return 0;
	ll t1=1,t2=1;
	fore(i,0,n){
		t1&=i%2==r[i];
		t2&=i%2==(r[i]^1);
	}
	assert(!t1||!t2);
	if(t1)return 1;
	if(t2)return 2;
	return 3;
}

int main(){FIN;
	ll n; cin>>n;
	assert(n>=3);
	map<ll,mat> mp;
	ll mx=2*n*(n-1);
	ll cant=mx-1; // 0 si, 1 no, mx-1 no
	mat a(n,vv(n));
	fore(mk,0,1ll<<(n*n)){
		ll mk2=mk;
		fore(i,0,n)fore(j,0,n)a[i][j]=mk2&1,mk2>>=1;
		vv ts;
		fore(i,0,n)ts.pb(get_ty(a[i]));
		if(count(ALL(ts),3)>1)continue;
		ll p=n;
		fore(i,0,n)if(ts[i]!=1&&ts[i]!=2){p=i;break;}
		ll bad=0;
		fore(i,0,p-1)if(ts[i]==ts[i+1])bad=1;
		fore(i,p+1,n)if(ts[i])bad=1;
		if(bad)continue;

		ll cur=0;
		fore(i,0,n)fore(j,0,n){
			if(i+1<n)cur+=(a[i][j]!=a[i+1][j]);
			if(j+1<n)cur+=(a[i][j]!=a[i][j+1]);
		}
		if(!mp.count(cur)){
			mp[cur]=a;
			if(SZ(mp)==cant)break;
		}
	}
	assert(SZ(mp)==cant);
	for(auto [c,a]:mp){
		cout<<c<<":\n";
		for(auto r:a){
			for(auto i:r)cout<<i;
			cout<<"\n";
		}
		show(vv(0));
	}
	return 0;
}
