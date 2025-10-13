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
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6+5;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
const ll haf=(MOD+1)/2;

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; n++;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll fg=1;
		fore(i,0,n)if(a[i]!=i&&a[i]!=0&&a[i]!=-1){
			ll to=a[i];
			if(to>=n){
				fg=0; continue;
			}
			if(a[to]==-1)a[to]=i;
			else fg&=a[to]==i;
		}
		ll c=0;
		fore(i,1,n)c+=a[i]==-1;
		vv pot(n+5); pot[0]=1;
		vv poti(n+5); poti[0]=1;
		fore(i,1,SZ(pot)){
			pot[i]=mul(pot[i-1],2);
			poti[i]=mul(poti[i-1],haf);
		}
		ll lib=a.back()==-1;
		c-=lib;
		ll res=0;
		// cerr<<c<<" c\n";
		// cerr<<lib<<" lib\n";
		// imp(a)
		fore(p,0,c+5)fore(bo,0,lib+1){
			ll tot=2*p+bo,otr=c-tot;
			if(otr<0)continue;
			ll num=fc[c];
			ll den=mul(poti[p],fci[otr]);
			den=mul(den,fci[p]);
			ll coef=pot[otr];
			ll cur=mul(mul(num,den),coef);
			// cout<<p<<" "<<bo<<": "<<cur<<"\n";
			res=add(res,cur);
		}
		if(!fg)res=0;
		cout<<res<<"\n";
	}
	return 0;
}
