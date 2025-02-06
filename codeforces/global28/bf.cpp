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

ii get(vector<vv> &a){
	ll n=SZ(a),m=SZ(a[0]);
	ll r0=-1,r1=-1;
	fore(i,0,n){
		ll mx=0;
		fore(j,0,m)mx=max(mx,a[i][j]);
		if(r0==-1||mx<r0)r0=mx;
	}
	fore(j,0,m){
		ll mn=0;
		fore(i,0,n)mn=min(mn,a[i][j]);
		if(r1==-1||mn>r1)r1=mn;
	}
	return {r0,r1};
}

int main(){FIN;
	ll n,m,v; cin>>n>>m>>v;
	vv pot(n*m+1); pot[0]=1;
	fore(i,1,SZ(pot))pot[i]=pot[i-1]*v;
	fore(mk,0,pot.back()){
		vector<vv>a(n,vv(m));
		ll num=mk;
		fore(i,0,n)fore(j,0,m)a[i][j]=num%v,num/=v;
		auto [l,r]=get(a);
		assert(l>=r);
		if(l<=r){
			for(auto v:a)imp(v)
			cout<<l<<" , "<<r<<"\n\n";
		}
	}
	return 0;
}
