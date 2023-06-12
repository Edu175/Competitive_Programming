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
const ll MOD=998244353,MAXF=1.5e6;

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
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
int main(){FIN;
	ll k; cin>>k;
	ll n=(1ll<<k);
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]-=(a[i]!=-1);
	factorials();
	ll r=1ll<<k,l=r/2;
	ll res=1;
	while(SZ(a)>1){
		//cout<<l<<" "<<r<<":\n";
		//imp(a);
		vector<ll>b;
		ll q=0;
		for(ll i=0;i<SZ(a);i+=2){
			if(a[i]>a[i+1])swap(a[i],a[i+1]);
			ll c=(a[i]==-1)+(a[i+1]==-1);
			//cout<<i<<": "<<a[i]<<" "<<a[i+1]<<": "<<c<<"\n";
			if(c==0){
				if(a[i+1]<l||a[i]>=l)res*=0;
				//cout<<"z: "<<(a[i+1]<l)<<" "<<(a[i]>=l)<<"\n";
				b.pb(a[i]);
			}
			else if(c==1){
				if(a[i+1]>=l)b.pb(a[i]);
				else q++,b.pb(a[i+1]);
			}
			else q++,res=res*2%MOD,b.pb(a[i]);
		}
		res=res*fc[q]%MOD;
		//cout<<res<<"\n";
		a=b;
		l/=2,r/=2;
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
