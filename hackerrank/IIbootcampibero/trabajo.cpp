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
typedef long double ld;
typedef pair<ll,ll> ii;

vector<ld> f(ll n){
	vector<ld>a(n,n);
	if(n==1)return a;
	vector<ld>add=f(n/2);
	for(auto i:f((n+1)/2))add.pb(i);
	fore(i,0,n/2)add[i]=add[n-1-i]=(add[i]+add[n-1-i])/2.0;
	fore(i,0,n)a[i]+=add[i];
	return a;
}

int main(){FIN;
	ll n; cin>>n;
	cout<<fixed<<setprecision(15);
	imp(f(n));
	return 0;
}
//mi primera chamba
