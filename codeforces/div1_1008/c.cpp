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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int sig(int s, int v){return s==1?v:sub(0,v);}
ll med=(MOD+1)/2;
// ll dbg=0;
struct node{
	ll res0,res1,sum0,sum1,cnt0,cnt1;
	node():res0(0),res1(0),sum0(0),sum1(0),cnt0(1),cnt1(0) {}
	void ad(ll d){
		// cout<<to_string((ll)this).substr(12)<<" ad "<<d<<"\n";
		// ++dbg;
		if(d==1){
			ll res1_=add(add(res1,res0),mul(sum0,med));
			ll res0_=add(add(res0,res1),mul(add(sum1,cnt1),med));
			res0=res0_;
			res1=res1_;
		}
		else {
			ll res1_=add(res1,sub(res0,mul(sum0,med)));
			ll res0_=add(res0,sub(res1,mul(sub(sum1,cnt1),med)));
			res0=res0_;
			res1=res1_;
		}
		// cout<<resi<<" "<<resi2<<"\n";
		// res=add(res,add(resi,resi2));
		d=sub(d,0);
		ll sum0_=add(sum0,add(sum1,mul(d,cnt1)));
		ll sum1_=add(sum1,add(sum0,mul(d,cnt0)));
		ll cnt0_=add(cnt0,cnt1);
		ll cnt1_=add(cnt0,cnt1);
		sum0=sum0_; sum1=sum1_;
		cnt0=cnt0_; cnt1=cnt1_;
		// cout<<res0<<","<<res1<<" "<<sum0<<","<<sum1<<" "<<cnt0<<","<<cnt1<<"\n";
	}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		ll sq=sqrt(n)+.5,m=(n+sq-1)/sq;
		vv val(n+1);
		for(ll p=0;p<n;){
			ll z=(!p?n%sq:sq); if(!z)z=sq;
			// cout<<p<<": "<<z<<"\n";
			node me;
			fore(i,0,p)me.ad(1);
			fore(i,0,n-p-z)me.ad(-1);
			fore(i,0,z+1){
				auto he=me;
				fore(j,0,i)he.ad(1);
				fore(j,0,z-i)he.ad(-1);
				ll res=add(he.res0,he.res1);
				val[p+i]=res;
				// cout<<"res "<<i+p<<": "<<res<<"\n";
			}
			p+=z;
		}
		// cerr<<dbg<<"\n";
		// imp(val)
		vv c(2);
		string s; cin>>s;
		for(auto i:s)c[i-'0']++;
		while(q--){
			ll p; cin>>p; p--;
			c[s[p]-'0']--;
			s[p]^=1;
			c[s[p]-'0']++;
			cout<<val[c[1]]<<"\n";
		}
	}
	return 0;
}
