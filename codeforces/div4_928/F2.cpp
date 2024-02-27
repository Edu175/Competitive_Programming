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
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
ll cv(ii p){return 7*p.fst+p.snd;}
ii cv(ll x){return {x/7,x%7};}
ll encode(ll i, ll j){
	ll x=cv({i,j})/2;
	return 1ll<<x;
}
vector<ll>cros[2],valid[2];
bool has[1ll<<25][2];
void dfs(ll mk, ll b){
	if(has[mk][b])return;
	has[mk][b]=1;
	fore(i,0,25)if(!((mk>>i)&1))dfs(mk|(1ll<<i),b);
}
short dp[1ll<<25][2];

int main(){FIN;
	fore(i,1,6)fore(j,1,6){
		ll b=(i+j)%2;
		cros[b].pb(
		encode(i-1,j-1)|
		encode(i-1,j+1)|
		encode(i+1,j-1)|
		encode(i+1,j+1)|
		encode(i,j));
	}
	fore(b,0,2)for(auto i:cros[b])dfs(i,b);
	//cout<<SZ(cros[0])<<" "<<SZ(cros[1])<<endl;
	//imp(cros[0]); imp(cros[1]);
	//cout<<endl;
	fore(mk,0,1ll<<25)fore(b,0,2){
		short &res=dp[mk][b];
		if(!has[mk][b]){res=0;continue;}
		res=100;
		fore(i,0,25)if(mk&(1ll<<i))res=min(res,short(1+dp[mk^(1ll<<i)][b]));
	}
	//cout<<SZ(valid[0])<<" "<<SZ(valid[1])<<"\n";
	ll t; cin>>t;
	while(t--){
		char a[7][7];
		ll m[2]={};
		fore(i,0,7)fore(j,0,7){
			cin>>a[i][j];
			if(a[i][j]=='B')m[(i+j)%2]|=encode(i,j);
		}
		ll res=dp[m[0]][0]+dp[m[1]][1];
		cout<<res<<"\n";
	}
	return 0;
}
