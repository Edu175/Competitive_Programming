#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#define bint __int128

struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
	ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
	ll mul(bint a, bint b){return a*b%MOD;}
	vector<bint> h,pi;
	Hash(string &s){
		assert(mul(P,PI)==1);
		h.resize(SZ(s)+1); pi=h;
		h[0]=0;pi[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=mul(pi[i-1],PI);
			p=mul(p,P);
		}
	}
	ll get(int s, int e){
		return mul(sub(h[e],h[s]),pi[s]);
	}
};

int main(){
	JET
	string s,t;
	cin>>s>>t;
	ll c0=count(ALL(s),'0'),c1=SZ(s)-c0;
	Hash hsh(t);
	ll res=0;
	fore(n,1,SZ(t)+1){
		ll num=SZ(t)-n*c0;
		if(num<=0||num%c1)continue;
		ll m=num/c1;
		vv h(2,-1);
		ll p=0,fg=1;
		for(auto i:s){
			i-='0';
			ll cur=hsh.get(p,p+(i?m:n)); p+=(i?m:n);
			if(h[i]==-1)h[i]=cur;
			else fg&=cur==h[i];
		}
		fg&=h[0]!=h[1];
		if(fg){
			res++;
			// cout<<n<<" "<<m<<"\n";
		}
	}
	cout<<res<<"\n";
	return 0;
}


