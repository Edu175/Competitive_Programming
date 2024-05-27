#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1ll<<19;
ll ask(ll i, ll j){
	cout<<"? "<<i<<" "<<j<<endl;
	ll ret; cin>>ret;
	return ret;
}
ll n,l,r;
ll dp[MAXN][2];
ll f(ll k, ll s, ll e, ll b){
	ll &res=dp[k][b];
	if(res!=-1)return res;
//	cout<<"visit "<<k<<" "<<s<<","<<e<<" "<<b<<"\n";
	if(l<=s&&e<=r){
		if(b)return res=0;
		else return res=1;
	}
	if(e<=l||r<=s){
		if(b)return res=1;
		else return res=0;
	}
	res=n+5;
	ll m=(s+e)/2;
	fore(w,0,2){
		res=min(res,w+f(2*k,s,m,b^w)+f(2*k+1,m,e,b^w));
	}
//	cout<<"ans "<<k<<" "<<s<<","<<e<<" "<<b<<": "<<res<<"\n";
	return res;
}
vector<ll>ans;
void build(ll k, ll s, ll e, ll b){
	ll &res=dp[k][b];
	if(l<=s&&e<=r){
		if(!b)ans.pb(k);
		return;
	}
	if(e<=l||r<=s){
		if(b)ans.pb(-k);
		return;
	}
	ll m=(s+e)/2;
	fore(w,0,2){
		if(res==w+f(2*k,s,m,b^w)+f(2*k+1,m,e,b^w)){
			if(w){
				if(b)ans.pb(-k);
				else ans.pb(k);
			}
			build(2*k,s,m,b^w),build(2*k+1,m,e,b^w);
			break;
		}
	}
}
int main(){FIN;
	cin>>n>>l>>r; r++;
	mset(dp,-1);
	f(1,0,1ll<<n,0);
	build(1,0,1ll<<n,0);
	ll res=0;
	for(auto x:ans){
		ll men=x<0;
		x=abs(x);
		ll k=63-__builtin_clzll(x);
		res+=(men?-1:1)*ask(n-k,x-(1ll<<k));
	}
	res=(res%100+100)%100;
	cout<<"! "<<res<<endl;
	return 0;
}
