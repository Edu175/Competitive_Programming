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
typedef unsigned __int128 xul;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ull P=1777771;

const ull MOD=(1ull<<61)-1;
inline ull add(ull a, ull b){a+=b;if(a>=MOD)a-=MOD;return a;}
inline ull red(xul a){ // up to mod+mod*mod = (mod+1)*mod = mod<<61
	return add(a>>61,a&MOD);
}
inline ull mul(ull a, ull b){return red(a*xul(b));}

ull pots[21]; // P^(2^i)
ll k,n;
const ll MAXN=(19<<18)+5;
ull mem[MAXN];
bool vis[MAXN];
string s;
ull full(ll x){ // get full
	auto &res=mem[x];
	auto &vi=vis[x];
	if(vi)return res;
	vi=1;
	ll d=(x>>k);
	if(d==0)return res=s[x];
	ll tam=d-1;
	ll le=x-n,ri=le^(1<<tam);
	res=red(full(le)+full(ri)*xul(pots[tam]));
	return res;
}

string xoration(ll x){
	string t(n,'.');
	fore(i,0,n)t[i]=s[i^x];
	return t;

}

bool cmp(ll x, ll y){
	x+=k<<k; y+=k<<k;
	fore(_,0,k){
		ll d=x>>k,tam=d-1; assert((y>>k)==d);
		ll lx=x-n;
		ll ly=y-n;
		if(full(lx)==full(ly)){
			lx^=(1<<tam),ly^=(1<<tam);
		}
		x=lx,y=ly;
	}
	return s[x]<s[y];
}
int main(){FIN;
	cin>>k;
	n=1ll<<k;
	cin>>s;
	ll mn=0;
	fore(_,0,10){
		mset(vis,0);
		pots[0]=P;
		fore(i,1,k+2)pots[i]=mul(pots[i-1],pots[i-1]);
		mn=0;
		fore(i,1,n)if(cmp(i,mn))mn=i;
	}
	cerr<<"mn "<<mn<<"\n";
	cout<<xoration(mn)<<"\n";
	return 0;
}
