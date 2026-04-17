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
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
string n,m;
const ll MAXN=1e4+5;
ll dp[MAXN][2][2];
ll f(ll i, ll b, ll t){
	auto &res=dp[i][b][t];
	if(res!=-1)return res;
	if(i==SZ(n))return res=t;
	res=0;
	ll e=b?n[i]-'0':9;
	fore(d,i==0||i==SZ(n)-1,e+1){
		ll ti=t;
		if(d>m[i]-'0')ti=0;
		if(d<m[i]-'0')ti=1;
		ll cur=f(i+1,b&&d==e,ti);
		res=add(res,cur);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		if(SZ(n)!=SZ(m)){
			if(SZ(n)>SZ(m))swap(n,m);
		}
		else if(n>m)swap(n,m);
		if(SZ(m)>SZ(n))m=string(SZ(n),'9');
		assert(SZ(n)==SZ(m));
		ll res=0;
		fore(d,2,SZ(n)){
			ll tot=mul(9*9,fpow(10,d-2));
			ll pals=mul(9,fpow(10,(d+1)/2-1));
			ll cur=sub(tot,pals);
			// cerr<<d<<": "<<tot<<" "<<pals<<": "<<cur<<"\n";
			res=add(res,cur);
		}
		// cerr<<n<<" "<<m<<" n m\n";
		// cerr<<res<<" #d < sz\n";
		reverse(ALL(m));
		fore(i,0,SZ(n)+3)fore(j,0,2)fore(k,0,2)dp[i][j][k]=-1;
		ll all=f(0,1,1);
		ll pali=0;
		ll h=(SZ(n)+1)/2;
		fore(d,0,h){
			ll cur=fpow(10,h-1-d);
			ll coef=n[d]-'0';
			coef-=d==0;
			cur=mul(cur,coef);
			pali=add(pali,cur);
		}
		string p(SZ(n),'.');
		fore(i,0,SZ(n))p[i]=n[min(i,SZ(n)-1-i)];
		pali=add(pali,p<=n);
		// cerr<<all<<" "<<pali<<"\n";
		res=add(res,sub(all,pali));
		cout<<res<<"\n";
	}
	return 0;
}
