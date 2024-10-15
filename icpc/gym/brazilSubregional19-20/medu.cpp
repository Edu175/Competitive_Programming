#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	FIN
	ll n,c,t; cin>>n>>c>>t;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	auto can=[&](ll x){
		ll k=0,s=0;
		fore(i,0,n){
			if(a[i]>x*t)return (bool)0;
			s+=a[i];
			if(s>x*t)k++,s=a[i];
		}
		k++;
		return k<=c;
	};
	ll l=0,r=1e10;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
} 