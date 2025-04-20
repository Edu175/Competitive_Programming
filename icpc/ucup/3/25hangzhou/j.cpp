#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXF=105;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
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
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
ll comb(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	ll res=fci[k];
	fore(i,0,k)res=mul(res,n-i);
	return res;
}
#define ppc __builtin_popcountll
#define bin(mk) fore(i,0,m)cout<<(mk>>i&1);;
int main(){
	JET
	factos();
	ll t; cin>>t;
	while(t--){
		ll n1,n2,m; cin>>n1>>n2>>m;
		ll k; cin>>k;
		vv bad(m,1);
		vv g(m);
		fore(i,0,k){
			ll a,b; cin>>a>>b; a--,b--;
			bad[a]=bad[b]=0;
			g[a]|=1ll<<b;
			g[b]|=1ll<<a;
		}
		ll good=0;
		fore(i,0,m)good+=!bad[i];
		vector<vv>cu(2,vv(m+1));
		fore(bo,0,2){
			fore(mi,0,m+1){
				cu[bo][mi]=comb((bo?n1:n2)+m-good-1,m-mi-1);
			}
		}
		ll M=1ll<<m;
		vv fgs(M);
		fore(mk,0,M){
			ll fg=1;
			fore(i,0,m)if(mk>>i&1)fg&=!bad[i]&&!(mk&g[i]);
			fgs[mk]=fg;
		}
		vv sp(M);
		fore(mk,0,M)if(fgs[mk])sp[mk]=cu[1][ppc(mk)];
		fore(j,0,m)fore(mk,0,M){
			if(mk>>j&1)sp[mk]=add(sp[mk],sp[mk^(1ll<<j)]);
		}
		ll res=0,all=M-1;
		fore(mk,0,M)if(fgs[mk]){
			ll resi=cu[0][ppc(mk)];
			resi=mul(resi,sp[~mk&all]);
			res=add(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}