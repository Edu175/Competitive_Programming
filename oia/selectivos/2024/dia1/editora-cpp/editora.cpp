#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto mjgltr:v)cout<<mjgltr<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=2e9;
int editora(vector<int> &tin, vector<long long> &a, string &ord) {
	int n=SZ(a);
	int N=1ll<<n;
	ll sum[N];
	fore(mk,0,N){
		sum[mk]=0;
		fore(i,0,n)if(mk>>i&1)sum[mk]+=a[i];
	}
	auto tinta=[&](ll v){
		int res=0;
		while(v)res+=tin[v%10],v/=10;
		return res;
	};
	int dp[N]={};
	dp[N-1]=0;
	for(int mk=N-2;mk>=0;mk--){
		auto &res=dp[mk];
		res=INF;
		fore(x,0,n)if(!(mk>>x&1)){
			res=min(res,tinta(sum[mk]+1)+dp[mk|(1<<x)]);
		}
	}
	//build
	ll mk=0;
	ord.clear();
	while(mk!=N-1){
		fore(x,0,n)if(!(mk>>x&1)){
			if(dp[mk]==tinta(sum[mk]+1)+dp[mk|(1<<x)]){
				//cout<<mk<<": "<<x<<" -> ";
				ord.pb('A'+x);
				mk|=1<<x;
				//cout<<mk<<"\n";
				break;
			}
		}
	}
	//reverse(ALL(ord));
	//for(auto &i:ord)i++;
	return dp[0];
}
