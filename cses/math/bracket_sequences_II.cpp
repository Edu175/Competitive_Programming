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
const ll MAXF=1e6+5,MOD=1e9+7;

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
	ll n; cin>>n;
	ll s=0,flag=n%2==0;
	string a; cin>>a;
	for(auto i:a){
		s+=(i==')'?-1:1);
		flag&=s>=0;
	}
	ll m=n-SZ(a),d=s+(SZ(a)-s)/2;
	ll bad=nCr(m,n/2-1-d);
	ll tot=nCr(m,(m-s)/2);
	ll res=(tot-bad+MOD)*flag%MOD;
	//cout<<m<<" "<<s<<" "<<d<<"\n";
	cout<<res<<"\n";
	return 0;
}
