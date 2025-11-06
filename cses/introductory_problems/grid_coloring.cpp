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

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		string a; cin>>a;
		fore(j,0,m){
			ll s=a[j]-'A';
			ll t=(i+j)&1;
			if(s==t)t^=2;
			a[j]='A'+t;
		}
		cout<<a<<"\n";
	}
	return 0;
}