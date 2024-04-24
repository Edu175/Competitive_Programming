#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXN=3005,MAXF=MAXN+5;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
//MODULAR OPERATIONS
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}


ll sp[MAXN][MAXN]; // m-length strings with at most k ones
int main(){FIN;
	factorials();
	fore(m,0,MAXN){
		fore(k,0,MAXN){
			sp[m][k]=add((k?sp[m][k-1]:0),nCr(m,k));
			//if()
		}
	}
	ll n,c,k; cin>>n>>c>>k;
	vector<ll>divs;
	fore(i,1,n+1)if(n%i==0)divs.pb(i);
	ll res=0;
	fore(i,c,c+k+1)res=add(res,nCr(n,i));
	cout<<"initial res "<<res<<"\n";
	for(auto p:divs){
		cout<<p<<":\n";
		fore(l,c,p)/*if(k*p%n==0)*/{
			ll ki=(k+c)*p/n-l,bits=p-l-2+(l==p-1);
			if(ki<0)continue;
			ll resi=sp[bits][ki];
			res=sub(res,mul(resi,p-1));
			cout<<"   "<<l<<": "<<bits<<' '<<ki<<" = "<<resi<<" -= "<<mul(resi,p-1)<<"\n";
		}
	}
	//if()
	cout<<res<<"\n";
	return 0;
}

