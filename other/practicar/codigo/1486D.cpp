#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll n,k;
ll a[MAXN];

bool can(ll x){
	vector<ll>b(n),sp(n+1);
	fore(i,0,n)b[i]=a[i]>=x?1:-1;
	fore(i,1,n+1)sp[i]=sp[i-1]+b[i-1];
	ll mn=MAXN*2;
	fore(i,0,n+1){
		if(i-k>=0)mn=min(mn,sp[i-k]);
		if(sp[i]-mn>0)return 1;
	}
	return 0;
	
}
int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	ll l=0,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}