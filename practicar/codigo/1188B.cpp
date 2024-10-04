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
ll MOD;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll n,k; cin>>n>>MOD>>k;
	vector<ll>a(n),val(n);
	fore(i,0,n){
		cin>>a[i];
		val[i]=1;
		fore(j,0,4)val[i]=mul(val[i],a[i]);
		val[i]=sub(val[i],mul(k,a[i]));
	}
	map<ll,ll>mp;
	ll res=0;
	fore(i,0,n)res+=mp[val[i]]++;
	cout<<res<<"\n";
	return 0;
}