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
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]=(a[i]%n+n)%n;
	vector<ll> c(n);
	c[0]=1;
	ll sum=0;
	ll res=0;
	fore(i,0,n){
		//imp(c);
		sum=(sum+a[i])%n;
		res+=c[sum]++;
		//cout<<i<<": "<<sum<<" "<<(n-sum)%n<<": "<<c[(n-sum)%n]<<"\n";
		//c[sum]++;
	}
	cout<<res<<"\n";
	return 0;
}
