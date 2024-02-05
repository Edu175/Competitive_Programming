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

int main(){FIN;
	ll n; cin>>n;
	ll sum=0;
	vector<ll>a(n);
	fore(i,0,n){
		cin>>a[i];
		ll s; cin>>s;
		sum+=s;
	}
	ll c=0;
	sort(ALL(a));
	for(auto i:a)c+=i,sum-=c;
	cout<<sum<<"\n";
	return 0;
}
