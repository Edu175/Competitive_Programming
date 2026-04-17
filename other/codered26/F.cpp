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
const ll MOD=(119<<23)+1;
const ll B=60;
const ll MAXK=105;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
ll mem[MAXK][MAXK];
ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	auto &res=mem[n][k];
	if(res!=-1)return res;
	if(n==0)return res=1;
	return res=add(nCr(n-1,k-1),nCr(n-1,k));
}
ll dp[B][2][MAXK];
ll n;
ll f(ll i, ll ca, ll k){ // ca es carry obligatorio
	if(i==-1){
		ll ret=!ca&&!k; // no me pueden pedir carry ahora
		return ret;
	}
	auto &res=dp[i][ca][k];
	if(res!=-1)return res;
	
	ll bo=(n>>i&1);
	
	ll same=f(i-1,bo,k); // 0,0 / 1,1
	
	// dif suma p en cada termino:
	ll dif=0; // 1,0 / 0,1
	ll p=(1ll<<i)%MOD;
	ll pot=1;
	fore(j,0,k+1){
		ll cur=mul(pot,f(i-1,!bo,k-j));
		cur=mul(nCr(k,j),cur);
		// cur=C(k,j) * p^j * sum (term^(k-j))
		dif=add(dif,cur);
		pot=mul(pot,p);
	}
	dif=mul(dif,2); // pongo 1,0 o 0,1
	
	
	if(!bo){
		res=ca?add(dif,same):same; // 1,0 + 0,1 + 1,1 : 0,0
	}
	else {
		res=ca?same:add(dif,same); // 1,1 : 1,0 + 0,1 + 0,0
	}
	
	return res;
}

int main(){FIN;
	mset(mem,-1);
	ll k; cin>>n>>k;
	mset(dp,-1);
	ll res=f(__lg(n),0,k);
	cout<<res<<"\n";
	return 0;
}
