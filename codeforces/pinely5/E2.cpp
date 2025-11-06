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
const ll MOD=998244353;
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
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k; k--;
		array<ll,3> state={0,0,0};
		ll now=1;
		// for B(l,r,n) [l,r] :
		// 2*B(l,r,n)=nCr(n,l)+nCr(n,r)-nCr(n+1,l)+B(l,r,n+1)
		// -nCr(n,l)-nCr(n,r)+nCr(n+1,l)+2*B(l,r,n)=B(l,r,n+1)
		auto actu=[&](ll dn, ll dl, ll dr){
			auto &[l,r,n]=state;
			while(dl<l)now=add(now,nCr(n,--l));
			while(l<dl)now=sub(now,nCr(n,l++));
			
			while(dr<r)now=sub(now,nCr(n,r--));
			while(r<dr)now=add(now,nCr(n,++r));
			
			while(n<dn){
				now=mul(now,2);
				now=sub(now,nCr(n,l));
				now=sub(now,nCr(n,r));
				now=add(now,nCr(n+1,l));
				n++;
			}
			while(dn<n){
				n--;
				now=add(now,nCr(n,l));
				now=add(now,nCr(n,r));
				now=sub(now,nCr(n+1,l));
				now=mul(now,(MOD+1)/2);
			}
		};
		
		auto get=[&](ll n, ll l, ll r)-> ll {
			if(l>r||r<0)return 0;
			actu(n,l,r);
			
			// if(1){
			// 	ll dbg=0;
			// 	fore(i,l,r+1)dbg=add(dbg,nCr(n,i));
			// 	assert(dbg==now);
			// }
			
			return now;
		};
		
		string s; cin>>s;
		vv cl(2),cr(2);
		for(auto i:s)if(i!='?')cl[i-'0']++;
		vv p(k,-1);
		ll res=0;
		for(ll i=n-1;i>=0;i--){
			fore(w,0,2)if(cl[w^1]==0){
				assert(!(s[i]=='0'+(w^1)));
				// if(s[i]=='0'+(w^1))continue;
				if(i<n-1&&p[(i+1)%k]==w)continue;
				ll did=0;
				if(i<n-1&&p[(i+1)%k]==-1)cr[w^1]++,did=1;
				// ll lib=k-cr[0]-cr[1],c0=k/2-cr[0];
				// ll sob=max(0ll,i+1+k-n);
				ll ten=min(k,n-i-1);
				// ll l=max(0ll,ten-cr[0]-k/2);
				// ll r=min(k/2-cr[0],ten-cr[0]-cr[1]);
				ll l=0ll;
				ll r=min(k/2-cr[w^1],ten-cr[w^1]-cr[w]);
				
				if(i+k+1<n){
					l=max(l,k/2-cr[w^1]);
				}
				
				ll nc=ten-cr[0]-cr[1];
				ll cur=get(nc,l,r);
				
				res=add(res,cur);
				// cout<<i<<" "<<w<<": "<<cr[0]<<" "<<cr[1]<<": "<<nc<<" "<<l<<","<<r<<" "<<": "<<cur<<"\n";
				if(did)cr[w^1]--;
			}
			ll w=s[i]=='?'?-1:s[i]-'0';
			if(w!=-1){
				auto &sh=p[i%k];
				if(sh==-1)sh=w,cr[w]++;
				if(sh!=w)break; // if bad break
				cl[w]--;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
