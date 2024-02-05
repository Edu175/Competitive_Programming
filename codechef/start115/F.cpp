#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXF=2e6+5;

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

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		ll res=0;
		fore(s,0,m+1){
			ll x=(s+k-1)/k;
			ll qan=0;
			if(s%k==0){
				qan=nCr(m-s+x,x);
			}
			else {
				qan=nCr(m-s+x-1,x-1);
			}
			//cout<<s<<" "<<x<<": "<<qan<<"*"<<nCr(s-x,n-x)<<" = ";
			qan=qan*nCr(s-x,n-x)%MOD;
			//cout<<qan<<" *"<<x<<" = "<<qan*x<<"\n";
			res=(res+qan*x)%MOD;
		}
		cout<<res<<"\n";
	}
	return 0;
}
