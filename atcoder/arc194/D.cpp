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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef pair<ll,ull> iu;
typedef vector<ll> vv;
const ll MAXN=5005,MOD=998244353,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
static uint64_t splitmix64(uint64_t x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}
vv g[MAXN];
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
iu f(ll x){
	map<ull,ii> mp;
	ull h=0;
	for(auto y:g[x]){
		auto [cf,hsh]=f(y);
		auto &par=mp[hsh];
		par.snd=cf;
		par.fst++;
		h+=hsh;
	}
	ll res=fc[SZ(g[x])];
	for(auto [hsh,par]:mp){
		auto [tam,cf]=par;
		ll cur=fpow(cf,tam);
		cur=mul(cur,fci[tam]);
		res=mul(res,cur);
	}
	h=splitmix64(h);
	return {res,h};
}

ll cnt=0;
ll p=0;
string s;

ll dfs(){
	assert(s[p++]=='(');
	ll x=cnt++;
	while(s[p]=='(')g[x].pb(dfs());
	assert(s[p++]==')');
	return x;
}

int main(){FIN;
	factos();
	ll asd; cin>>asd;
	cin>>s;
	s="("+s+")";
	ll rt=dfs();
	auto [res,hsh]=f(rt);
	// fore(x,0,cnt){
	// 	cout<<x<<": ";
	// 	for(auto y:g[x])cout<<y<<" ";;cout<<"\n";
	// }
	cout<<res<<"\n";
	return 0;
}
