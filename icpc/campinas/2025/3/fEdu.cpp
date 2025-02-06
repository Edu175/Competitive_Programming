#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll mod=504;
ll dp[20][mod][1ll<<10][2][2];

ll pot[19];

string S;
ll f(ll i, ll r, ll mk, ll did, ll fg, ll ult){
	auto &res=dp[i][r][mk][did][fg];
	if(i==SZ(S)){
		ll res=1;
		if(mk>>5&1)res&=ult;
		fore(i,2,10)if(i!=5&&(mk>>i&1))res&=r%i==0;
		return res;
	}
	if(res!=-1)return res;
	res=0;
	ll e=fg?S[i]-'0':9;
	fore(d,(did?1:0),e+1){
		res+=f(i+1,(r+d*pot[SZ(S)-1-i])%mod,mk|(1ll<<d),did|(d>0),fg&&d==e,!(d%5));
	}
	return res;
}

ll get(ll r){
	if(r==0)return 1;
	S=to_string(r);
	mset(dp,-1);
	return f(0,0,0,0,1,0);
}

int main(){
	JET
	pot[0]=1; fore(i,1,19)pot[i]=pot[i-1]*10;
	ll l,r; cin>>l>>r;
	cout<<get(r)-get(l-1)<<"\n";
	return 0;
}