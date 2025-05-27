#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=405,MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
vv mk[MAXN];
ll n;
bool is_anc(ll x, ll y){
	fore(i,0,n)if(!mk[x][i]&&mk[y][i])return 0;
	return 1;
}
vv ord;
ll vis[MAXN];
vv p;
ll anc[MAXN][MAXN];
void dfs(ll x){
	p.pb(x); vis[x]=1;
	for(auto y:ord)if(!vis[y]&&is_anc(x,y)){
		for(auto fa:p)anc[fa][y]=1;
		dfs(y);
	}
	p.pop_back();
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)mk[i]=vv(n),vis[i]=0;
		ord=vv(n); iota(ALL(ord),0);
		fore(i,0,n)fore(j,0,n)anc[i][j]=0;
		fore(i,0,n)fore(j,0,n)cin>>mk[i][j];
		vv cnts(n);
		fore(i,0,n)cnts[i]=count(ALL(mk[i]),1);
		sort(ALL(ord),[&](ll i, ll j){return cnts[i]>cnts[j];});
		dfs(0);
		fore(i,0,n)anc[i][i]=1;
		ll good=1;
		fore(i,0,n)good&=vis[i];
		fore(i,0,n)fore(j,0,n){
			if((anc[i][j]||anc[j][i])!=mk[i][j])good=0;
			// cout<<i<<","<<j<<": "<<anc[i][j]<<"\n";
		}
		// cout<<"good "<<good<<"\n";
		if(!good)cout<<"0\n";
		else {
			map<vv,ll>mp;
			fore(i,1,n)mp[mk[i]]++;
			ll res=1;
			for(auto [sdf,cnt]:mp){
				ll fc=1;
				fore(i,1,cnt+1)fc=mul(fc,i);
				// cout<<cnt<<" bucket\n";
				res=mul(res,fc);
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
