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
const ll P=-1e12;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv c(n);
		fore(i,0,n)cin>>c[i];
		vector<ii> bl;
		ll l=0;
		fore(i,0,n){
			if(i==n-1||s[i+1]=='0'){
				if(s[l]=='0')bl.pb({l,i+1});
				l=i+1;
			}
		}
		vv part(n); part[0]=a[0];
		fore(i,1,n)part[i]=part[i-1]+a[i];
		ll sum=0;
		ll po=0;
		for(auto [l,r]:bl){
			while(po<l)sum+=a[po++];
			ll p=-1;
			fore(i,l,r)if(!i||c[i]>c[i-1])p=i;
			ll x=P-sum;
			if(p!=-1){
				ll d=part[p]-part[l];
				x=c[p]-d-sum;
			}
			assert(s[l]=='0');
			a[l]=x;
		}
		vv b=a;
		fore(i,1,n)b[i]+=b[i-1];
		vv d=b;
		fore(i,1,n)d[i]=max(d[i],d[i-1]);
		// show(a)
		// show(d)
		if(d==c){
			cout<<"Yes\n";
			show(a)
		}
		else cout<<"No\n";
	}
	return 0;
}
