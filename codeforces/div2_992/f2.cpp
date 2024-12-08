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
// #pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MOD=998244353,MAXF=5e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
random_device rd;
mt19937 rng(rd());
int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll a,b,c; cin>>a>>b>>c;
		ll dp3[a][b][c];
		ll dp2[b][c];
		ll dp1[c];
		auto get=[&](ll k, ll n){
			return n/gcd(n,k);
		};
		fore(i,0,c)dp1[i]=get(i,c);
		fore(y,0,b)fore(z,0,c){
			ll p=b/gcd(b,y);
			dp2[y][z]=p*dp1[z*p%c];
		}
		fore(x,0,a)fore(y,0,b)fore(z,0,c){
			ll p=a/gcd(a,x);
			dp3[x][y][z]=p*dp2[y*p%b][z*p%c];
		}
		ll inve=fpow(a*b*c,MOD-2),sum=0;
		vv coef(a*b*c+1);
		fore(x,0,a)fore(y,0,b)fore(z,0,c){
			ll t=dp3[x][y][z];
			// cout<<x<<" "<<y<<" "<<z<<": "<<t<<endl;
			ll n=a*b*c/t;
			// n same-colour groups of size t
			cout<<x<<" "<<y<<" "<<z<<": "<<gcd(a,x)<<" -> "<<n<<"\n";
			coef[n]++;
		}
		imp(coef)
		ll k; cin>>k;
		vv d(k);
		fore(i,0,k)cin>>d[i];
		shuffle(ALL(d),rng);
		fore(n,0,SZ(coef))if(coef[n]){
			assert(a*b*c%n==0);
			ll resi=fc[n];
			ll t=a*b*c/n;
			for(auto i:d){
				if(i%t){resi=0;break;}
				resi=mul(resi,fci[i/t]);
			}
			resi=mul(resi,coef[n]);
			sum=add(sum,resi);
		}
		ll res=mul(inve,sum);
		cout<<res<<"\n";
	}
	return 0;
}
