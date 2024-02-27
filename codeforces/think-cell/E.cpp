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
const ll MOD=998244353,MAXF=1e6+5;
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
ll ceb(ll c, ll b){return nCr(c+b-1,c-1);}
int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(k,1,(n-1)/2+1){
			ll res=1;
			//cout<<"\nk "<<k<<":\n";
			for(ll m=2*k;m<n;m+=2*k){
				ll resi=(ceb(m+1,n-m)-ceb(2*k,n-m)+MOD)%MOD;
				res=(res+resi)%MOD;
				//cout<<"m "<<m<<": "<<resi<<"\n";
			}
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
