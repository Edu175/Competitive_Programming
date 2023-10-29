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
const ll MOD=998244353,MAXF=3e5+5;

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
/*ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
ll nVr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[n-k]%MOD;
}*/

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		vector<ll>p;
		ll q=1;
		fore(i,1,SZ(s)){
			if(s[i]!=s[i-1])p.pb(q),q=1;
			else q++;
		}
		p.pb(q);
		ii res={0,1};
		for(auto i:p)assert(i),res.fst+=i-1,res.snd=res.snd*fc[i]%MOD;
		cout<<res.fst<<" "<<res.snd<<"\n";
	}
	return 0;
}
