#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first 
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
ll MOD;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(LL a, LL b){return a*b%MOD;}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll res=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)res=mul(res,b);
	return res;
}
ll inv(ll a){return fpow(a,MOD-2);}


const int maxn = 10001;
ll in[maxn];


ii v[maxn * maxn];


int main(){
	JET
	ll n; cin>>n>>MOD;
	fore(i,1,maxn) in[i] = inv(i);
	vv a(n); iota(ALL(a),1);
	
	ll c = 0;
	
	fore(i,1,n+1)fore(j,max(n+1-i,i),n+1) v[c++] = {i*j,j};
	sort(v,v+c);
	
	ll res = 1;
	fore(i,0,n)res = mul(res,a[i]);
	ll rta = 0;
	
	auto f = [&](ll val, ll p){
		res = mul(res,in[a[p]]);
		ll acc = mul(res,val);
		rta = add(acc,rta);
		a[p]--;
		res = mul(res,a[p]);
		if(!res) return true;
		return false;
	};
	while(c--){
		auto [x,y] = v[c];
		ll p = x/y-1, p1 = y-1;
		ll b = f(x,p);
		if(b) break;
		if(p != p1) b = f(x,p1);
		if(b) break;
	}
	cout<<rta<<"\n";
	
	return 0;
}