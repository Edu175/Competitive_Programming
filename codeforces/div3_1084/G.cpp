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
const ll MAXF=3005;
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

ll inv(ll a){return fpow(a,MOD-2);}

#define addig(a,b) a=add(a,b)

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,X; cin>>n>>X;
		vector<char> t(n); vv a(n);
		auto val=[&](ll i)-> ll {
			if(t[i]=='+'||t[i]=='-')return -1;
			ll res=a[i];
			if(t[i]=='/')res=inv(res);
			return res;
		};
		ll prod=1,sum=0;
		fore(i,0,n){
			cin>>t[i]>>a[i];
			ll v=val(i);
			if(v!=-1)prod=mul(prod,v);
			else {
				if(t[i]=='-')a[i]*=-1;
				if(a[i]<0)a[i]+=MOD;
				addig(sum,a[i]);
			}
		}
		ll res=mul(X,prod);
		vector<vv> dp(n+1,vv(n+1));
		dp[0][0]=1;
		// vv skip(n);
		// ll did=0;
		// fore(i,0,n)if(val(i)==-1&&!did)skip[i]=1,did=1;
		// if(!did){
		// 	res=mul(res,fci[n]);
		// 	cout<<res<<"\n";
		// 	continue;
		// }
		ll num=0;
		fore(i,0,n+1)fore(l,0,i+1){
			auto &now=dp[i][l];
			if(i==n){
				addig(num,now);
				continue;
			}
			ll r=i-l;
			ll izq=l+1;
			ll der=r+1;
			ll v=val(i);
			if(v!=-1)der=mul(der,v);
			addig(dp[i+1][l+1],mul(izq,now));
			addig(dp[i+1][l],mul(der,now));
		}
		num=mul(num,inv(n+1)); // o n+1 ?
		ll agr=mul(sum,num);
		// cerr<<res<<" | "<<sum<<" "<<num<<": "<<agr<<"\n";
		agr=mul(agr,fci[n]);
		// cout<<agr<<": ";
		res=add(res,agr);
		cout<<res<<"\n";
	}
	return 0;
}
