#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {cout<<#v<<": "; for(auto i:v)cout<<i<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld INF=1e18;

int main(){
	JET
	ll lon,k,n; cin>>lon>>k>>n;
	vv ts(n+1),ds(n),dif(n);
	vector<ld> ps(n);
	fore(i,0,n)cin>>ts[i]>>ps[i]>>ds[i];
	ts[n]=lon;
	fore(i,0,n)dif[i]=ts[i+1]-ts[i];
	// imp(ts);
	// imp(dif);
	auto calc=[&](ld asu, ll fg=0){ // asumo rta
		vector<vector<ld>>dp(n+5,vector<ld>(k+5));
		auto f=[&](ll i, ll s){
			if(s>=k)return INF;
			return dp[i][s];
		};
		for(ll i=n-1;i>=0;i--)for(ll s=k;s>=0;s--){
			auto &res=dp[i][s];
			ld p=ps[i]; ll d=ds[i],df=dif[i];
			// res=p*(df+f(i+1,s+df))+
			// 	(1-p)*min(asu,d+f(i,s+d));
			// enunciado: sigo en i? (lo de abajo asume que no)
			res=p*(df+f(i+1,s+df))+
				(1-p)*min(asu,d+df+f(i+1,s+d+df));
			// if(fg)cout<<i<<" "<<s<<": "<<res<<"\n";
		}
		ld res=ts[0]+dp[0][ts[0]];
		if(fg)cout<<"calc "<<asu<<": "<<res<<"\n";
		return res;
	};
	// calc(124,1);
	// calc(3,1);
	ld l=0,r=INF;
	ll it=100;
	while(it--){
		ld m=(l+r)/2;
		if(m<calc(m))l=m;
		else r=m;
	}
	cout<<fixed<<setprecision(15)<<r<<"\n";
}