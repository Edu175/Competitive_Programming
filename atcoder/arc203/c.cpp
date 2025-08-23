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
const ll MOD=998244353,MAXF=1e6+5;
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

ll cam(ll n, ll m){
	return nCr(n+m-2,n-1);
}

ll comb(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	assert(k<MAXF);
	ll res=1;
	fore(i,0,k)res=mul(res,(n-i)%MOD);
	res=mul(res,fci[k]);
	return res;
}

ll anagram(ll a, ll b, ll c){
	if(a<0||b<0||c<0)return 0;
	ll res=fc[a+b+c];
	res=mul(res,fci[a]);
	res=mul(res,fci[b]);
	res=mul(res,fci[c]);
	return res;
}

ll get(ll a, ll b){
	if(a<0||b<0)return 0;
	ll res=anagram(a,b+2,1);
	ll sac=anagram(a,b+3,0);
	sac=mul(sac,2);
	res=sub(res,sac);
	return res;
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		// ll tot=add(mul(n,m-1),mul(n-1,m));
		ll tot=n*(m-1)+(n-1)*m;
		ll len=n+m-2; // in walls
		
		ll s=k-len;
		
		ll res=mul(cam(n,m),comb(tot-len,s));
		
		ll sac=mul(cam(n-1,m-1),n-1+m-1-1);
		// cerr<<tot<<": ";
		// cerr<<res<<" "<<sac<<" "<<s<<"\n";
		
		if(s==2){
			res=sub(res,sac);
			ll bad0=get(n-1 -2, m-1 -1);
			ll bad1=get(m-1 -2, n-1 -1);
			
			// cerr<<bad0<<" "<<bad1<<"\n";
			
			res=add(res,add(bad0,bad1));
		}
		cout<<res<<"\n";
		
	}
	return 0;
}
