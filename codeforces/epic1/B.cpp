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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,1,n){
			ll x=0;
			if(a[i]<a[i-1])x=a[i-1]-a[i];
			a[i]+=x;
			b[i]=x;
		}
		ll res=0,s=0;
		sort(ALL(b));
		fore(i,0,n){
			b[i]-=s;
			res+=(n-i+1)*(b[i]);
			s+=b[i];
		}
		cout<<res<<'\n';
	}
	return 0;
}
