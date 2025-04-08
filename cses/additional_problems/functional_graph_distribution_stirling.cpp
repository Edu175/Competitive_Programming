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

const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}

const ll MAXN=5005;
ll mem[MAXN][MAXN];

ll usn(ll n, ll k){ // unsigned stirling numbers of the first kind
	auto &res=mem[n][k];
	if(res!=-1)return res;
	if(k>n)return res=0;
	if(k==0)return res=n==0;
	return res=add(usn(n-1,k-1),mul(n-1,usn(n-1,k)));
}

int main(){FIN;
	factos();
	mset(mem,-1);
	ll n; cin>>n;
	vv pot(n+5); pot[0]=1;
	fore(i,1,SZ(pot))pot[i]=mul(pot[i-1],n);
	vv ans(n+1);
	fore(z,1,n+1){
		// number of forests with z rooted trees
		ll num=mul(mul(fc[n-1],fci[z-1]),mul(pot[n-z],fci[n-z]));
		fore(k,1,n+1)ans[k]=add(ans[k],mul(num,usn(z,k)));
	}
	fore(i,1,n+1)cout<<ans[i]<<"\n";
	return 0;
}