#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
//66 pts
const ll L=18;
const ll N=L+5,S=(1ll<<L)+5;
ii dp[N][S];
ll cho[N][S];
ii f(ll i, ll s){
	if(s<0)return {0,-1};
	if(i==-1)return {s==0,0};
	return dp[i][s];
}
int main(){FIN;
	fore(i,0,N)fore(s,0,S){
		auto &res=dp[i][s];
		fore(j,0,4){
			auto resi=f(i-1,s-(j<<i));
			resi.snd+=(j==3)<<i;
			if(resi>res)cho[i][s]=j,res=resi;
		}
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll k=63-__builtin_clzll(n);
		vector<ll>res(3);
		for(ll i=k,s=n;i>=0;i--){
			ll j=cho[i][s];
			fore(h,0,j)res[h]+=1ll<<i;
			s-=j<<i;
		}
		imp(res);
	}
	return 0;
}
