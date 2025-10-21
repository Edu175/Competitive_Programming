#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll my(string s){
	ll res=0;
	fore(i,0,SZ(s))res=res*10+s[i]-'0';
	return res;
}
void valid(string s, ll k){
	ll n=SZ(s);
	vv c(n);
	fore(i,0,n){
		if(s[i]=='?'){
			if(i==n-1||(i+2<n&&s[i+2]=='0')){
				if(i&&(s[i-1]=='?'||s[i-1]=='2'))
					c[i]=6;
				else c[i]=9;
			}
			else if(s[i+1]=='?')c[i]=2;
			else if(s[i+1]<='6')c[i]=2;
			else c[i]=1;
		}
		else c[i]=1;
	}
	imp(c)
	ll p=0,q=1;
	for(ll i=n-1;i>=0;i--){
		q*=c[i];
		if(q>k){p=i;break;}
	}
	// cout<<p<<" p\n";
	fore(i,0,p)if(s[i]=='?')s[i]='0'+c[i];
	fore(i,p,n)if(s[i]=='?'){
		q/=c[i];
		// cout<<i<<": "<<k<<": "<<q<<"\n";
		for(ll j=c[i]-1;j>=0;j--){
			if(k<q){s[i]='1'+j;break;}
			else k-=q;
		}
	}
	cout<<s<<" ";
	// cerr<<"\n";
	vector<ll>dp(n+5);
	dp[n]=1;
	for(ll i=n-1;i>=0;i--){
		ll &res=dp[i];
		if(s[i]=='0'){res=0;continue;}
		res=dp[i+1];
		if(i+1<n&&my(s.substr(i,2))<=26)
			res=add(res,dp[i+2]);
	}
	cout<<dp[0]<<endl;
	assert(dp[0]);
}
int main(){FIN;
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		string s; cin>>s;
		// cout<<s<<endl;
		ll k; cin>>k; k--;
		ll flag=1;
		if(s[0]=='0')flag=0;
		ll n=SZ(s);
		fore(i,0,n-1){
			if(s[i]=='0'&&s[i+1]=='0')flag=0;
		}
		if(flag)valid(s,k);
		assert(flag);
		
	}
	return 0;
}
