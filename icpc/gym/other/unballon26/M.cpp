#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-8;
int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<ld> p(n);
	fore(i,0,n){
		string s; cin>>s;
		ll pos=s.find('.');
		if(!count(ALL(s),'.'))pos=SZ(s);
		ll dsp=(SZ(s)-pos-1);
		dsp=max(dsp,0ll);
		ll pad=3-dsp; assert(pad>=0&&pad<=3);
		// cerr<<"s "<<s<<": "<<pos<<" "<<pad<<"\n";
		if(pos<SZ(s))s.erase(s.begin()+pos);
		ll num=stoll(s);
		fore(_,0,pad)num*=10;
		p[i]=ld(num)/1000;
	}
	auto dame=[&](ld ass)->ld { // ass de assume...
		vector<ld> dp(n+1);
		dp[n]=ass;
		for(ll i=n-1;i>=0;i--){
			ld sig=1+dp[i+1];
			ld no=(1-p[i])*sig;
			ld si=p[i]*min((ld)a[i],sig);
			dp[i]=no+si;
		}
		return dp[0];
	};
	// fixed point now
	ld x=0;
	while(1){
		auto y=dame(x);
		// cerr<<x<<" "<<y<<"\n";
		if(min(abs(x-y)/y,abs(x-y))<EPS){x=y;break;}
		x=y;
	}
	// cerr<<x<<": "<<dame(x)<<"\n";
	cout<<fixed<<setprecision(15);
	cout<<x<<"\n";
	return 0;
}
