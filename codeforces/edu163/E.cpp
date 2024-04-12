#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ll> get(ll n, ll s){
	vector<ll>a(n);
	ll c=n/2;
	fore(i,0,n){
		a[i]=(c-i+n)%n+s;
	}
	return a;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll res=(n+k-1)/k;
		vector<ll>a,c(n);
		for(ll i=0,q=0;i<n;i+=k,q++){
			auto b=get(min(n-i,k),i);
			for(auto j:b)a.pb(j);
			fore(j,i,min(i+k,n))c[j]=q;
		}
		fore(i,0,n)cout<<a[i]+1<<" ";;cout<<"\n";
		cout<<res<<"\n";
		fore(i,0,n)cout<<c[i]+1<<" ";;cout<<"\n";
		
	}
	return 0;
}
