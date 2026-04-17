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
const ll MAXN=2e5+5;

#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	//P[5]={1444441,1777771,1234567,1242421,1010003};
	vector<bint>pi,h;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1);
		pi[0]=1,h[0]=0;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+s[i-1]*p)%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(ll s, ll e){
		return ((h[e]-h[s]+MOD)*pi[s])%MOD;
	}
	bool valid(ll l, ll r, ll m){ //period m
		ll k=r-l-m;
		return get(l,l+k)==get(r-k,r);
	}
};
string s;
Hash h("");
ll m;
struct node{
	ll s,e,l,r,res;
};
node oper(node a, node b){
	node c=a;
	c.res=max(c.res,b.res);
	if()
	if(h.valid(a.s,b.r))
}
node f(ll l, ll r){
	if(r-l<=m)
}

int main(){FIN;
	cin>>s;
	ll n=SZ(s);
	h=Hash(s);
	
	return 0;
}
