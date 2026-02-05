#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define impr(v) for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
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

int main(){
    JET
    ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	ll ans=0;
	fore(i,1,n)fore(j,i+1,n){
		vv ids={0,i,j};
		vector<ii> ev;
		ll bad=0;
		for(auto me:ids){
			ll val=a[me];
			ev.pb({me,1});
			ll s=a[0]+a[i]+a[j]-val;
			ll to=lower_bound(ALL(a),s)-a.begin();
			bad|=to<=me;
			ev.pb({to,-1});
		}
		if(bad)continue;
		ev.pb({n,0});
		sort(ALL(ev));
		ll cnt=0,res=1;
		fore(i,0,SZ(ev)){
			cnt+=ev[i].snd;
			if(i+1<SZ(ev)){
				ll sz=ev[i+1].fst-ev[i].fst-(ev[i].snd==1);
				ll cur=fpow(cnt,sz);
				// cerr<<cnt<<" "<<sz<<": "<<cur<<"\n";
				res=mul(res,cur);
			}
		}
		// for(auto [a,b]:ev)cout<<a<<","<<b<<" ";;cout<<"\n";
		// cout<<i<<","<<j<<": "<<res<<" ==\n\n";
		ans=add(ans,res);
	}
	cout<<ans<<"\n";
    return 0;
}


