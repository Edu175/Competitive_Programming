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

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n){
		char c; cin>>c;
		a[i]=c=='B';
	}
	ll r=n-1,cnt=0;
	while(cnt+a[r]<=k)cnt+=a[r--];
	ll res=n-r-1 - cnt;
	fore(i,0,n){
		cnt+=a[i];
		while(r<n&&cnt>k)cnt-=a[r++];
		ll cur=n-max(r,i)-1 + i+1 - cnt;
		cerr<<i<<": "<<r<<" "<<cnt<<": "<<cur<<"\n";
		if(cnt<=k)res=max(res,cur);
	}
	cout<<res<<"\n";
	return 0;
}
