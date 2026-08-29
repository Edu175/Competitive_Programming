#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ld dp[105][1<<17];

int main(){
	JET
	ll n,maxt; cin>>n>>maxt;
	vv r(n),c(n);
	vector<ld> p(n);
	fore(i,0,n)cin>>r[i]>>c[i]>>p[i];
	dp[0][0]=1;
	vector<ld> prop(n);
	vector<vector<ld>> agr(maxt+1,vector<ld>(n));
	fore(t,0,maxt+1){
		fore(i,0,n)prop[i]+=agr[t][i];
		fore(mk,0,1ll<<n){
			auto &now=dp[t][mk];
			if(!now)continue;
			ld sum=0; ll cant=0;
			fore(w,0,n)if(!(mk>>w&1)){
				sum+=prop[w];
				cant++;
			}
			fore(w,0,n)if(!(mk>>w&1)){
				ld go=(sum?prop[w]/sum:1.0/cant);
				go*=now;
				if(!go)continue;
				ll ti=t+r[w];
				if(ti>maxt)continue;
				auto code=go*p[w];
				if(code){
					ll ti2=ti+c[w];
					if(ti2<=maxt){ // lo resolvio
						agr[ti2][w]+=code;
						dp[ti2][mk|(1ll<<w)]+=code;
					}
				}
				auto rest=go*(1-p[w]);
				if(rest){
					dp[ti][mk|(1ll<<w)]+=rest;
				}
			}
		}
	}
	cout<<fixed<<setprecision(15);
	for(auto x:prop)cout<<x<<"\n";
	return 0;
}
