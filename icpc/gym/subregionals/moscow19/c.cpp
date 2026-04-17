#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

ll n,k;
ll a[MAXN];
ll can0(){
	ll c=0;
	fore(i,0,n)c+=a[i]==0;
	return c>=k;
}
ll can1(){
	vv pos,que;
	fore(i,0,n)if(a[i]<=1){
		pos.pb(i);
		que.pb(a[i]);
	}
	if(!count(ALL(que),0))return 1;
	ll m=SZ(pos);
	pos.pb(n);
	// imp(que)
	// imp(pos)
	vector<vv>dp(m+3,vv(2));
	dp[m][0]=n+5;
	for(ll i=m-1;i>=0;i--)fore(fg,0,2){
		auto &res=dp[i][fg];
		if(que[i]){
			res=dp[i+1][1];
			continue;
		}
		res=dp[i+1][0]+pos[i+1]-pos[i];
		if(i&&fg){
			ll atr=pos[i]-pos[i-1]+dp[i+1][1];
			res=min(res,atr);
		}
	}
	ll d=dp[0][0];
	return d<=n-k;
}
ll can2(){
	vector<vv> sp(3,vv(n+1));
	fore(h,0,3){
		fore(i,1,n+1)sp[h][i]=sp[h][i-1]+(a[i-1]==h);
	}
	auto cant=[&](ll h, ll l, ll r){return sp[h][r]-sp[h][l];};
	ll z=n+1-k;
	fore(l,0,n-z+1){
		ll r=l+z;
		if(cant(0,l,r)&&cant(1,l,r)&&cant(2,l,r))return 1;
	}
	ll ult=-1,part=-1;
	fore(i,0,n)if(a[i]<=1){
		part+=(a[i]!=ult);
		ult=a[i];
	}
	return (k-1>=part);
}
int main(){
    JET
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	ll res=0;
	if(can0())res=0;
	else if(can1())res=1;
	else if(can2())res=2;
	else res=3;
	cout<<res<<"\n";
    return 0;
}