#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ll MOD;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	ll r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}

int main(){
	JET
	ll n,s; cin>>n>>s>>MOD;
	vv a(s);
	fore(i,0,s)	cin>>a[i];
	ll mn = 3e18,ant=-3e18;
	for(auto x:a){
		ll k = x-ant;
		mn=min(mn,k);
		ant = x;
	}
	reverse(ALL(a));
	for(auto x:a)if(x>=mn||s==1)mn=min(mn,(x+1)/2);
	reverse(ALL(a));
	if(mn>=a[0]&&s>1){
		mn-=a[0]/2;
	}
	mn+=n-ant;
	cout<<fpow(2,mn)<<"\n";
	return 0;
}