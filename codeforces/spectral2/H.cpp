#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3005,MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
ll dp[MAXN][MAXN];

vector<vv> sp;
vector<vv> nxt;
vv p0;//,otr0;
string s;
ll n;
bool hayp(ll i, ll j){
	return (sp[j][2]-sp[i][2]);
}
bool good(ll i, ll j){
	if(i>j)return 0;
	return hayp(i,j)||(sp[j][1]-sp[i][1])%2==0;
}
ll prox(ll i, ll b){
	if(i>=n)return n+1;
	ll j=!b?p0[i]:nxt[i][1];
	j++;
	return j;
}
ll f(ll i, ll j){
	assert(i<=j);
	auto &res=dp[i][j];
	if(res!=-1)return res;
	if(i==n)return res=1;
	if(i>n)return res=0;
	res=good(i,n)||good(j,n);
	fore(bo,0,2){
		ll pi=prox(i,bo);
		ll pj=prox(j,bo);
		ll ant=i;
		if(pi>pj)swap(pi,pj),ant=j;
		if(pi<=n&&hayp(ant,pi)){
			pj=nxt[pi][1]+1;
			if(!bo)pj=p0[pj]+1;
		}
		ll cur=f(pi,pj);
		// cout<<i<<","<<j<<" "<<bo<<": "<<pi<<","<<pj<<": "<<cur<<"\n";
		res=add(res,cur);
	}
	// cerr<<i<<","<<j<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		sp=vector<vv>(n+1,vv(3));
		fore(i,0,n){
			sp[i+1]=sp[i];
			ll ty=min(s[i]-'0',2);
			sp[i+1][ty]++;
		}
		nxt=vector<vv>(n+2,vv(3,n));
		for(ll i=n-1;i>=0;i--)fore(w,0,2){
			nxt[i][w]=nxt[i+1][w];
			if(s[i]!='0'+(w^1))nxt[i][w]=i;
		}
		p0=vv(n+2,n);
		fore(i,0,n){
			auto &j=p0[i];
			j=i;
			while(j<n&&(s[j]=='1'||!good(i,j)))j++;
		}
		// show(p0) cout<<endl;
		fore(i,0,n+3)mset(dp[i],-1);
		ll res=f(0,0);
		cout<<res<<"\n";
	}
	return 0;
}
