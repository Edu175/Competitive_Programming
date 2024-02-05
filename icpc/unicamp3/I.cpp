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

#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<bint> h,pi;
	bint cut(ll a){return a<MOD?a:a-MOD;}
	Hash(string&s){
		assert((P*PI)%MOD==1);
		h.resize(SZ(s)+1); pi.resize(SZ(s)+1);
		h[0]=1,pi[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(int s, int e){
		return cut(h[e]-h[s]+MOD)*pi[s]%MOD;
	}
};
int main(){FIN;
	string a,b,c;
	cin>>a>>b>>c;
	Hash h(a),hb(b),hc(c);
	ll idb=hb.get(0,SZ(b));
	ll idc=hc.get(0,SZ(c));
	set<ll>st[SZ(a)+1];
	vector<ll> god[2];
	fore(i,0,SZ(a)+1)if(i+SZ(b)<=SZ(a)&&h.get(i,i+SZ(b))==idb)god[0].pb(i);
	fore(i,0,SZ(a)+1)if(i-SZ(c)>=0&&h.get(i-SZ(c),i)==idc)god[1].pb(i);
	for(auto i:god[0])for(auto j:god[1]){
		if(j-i<SZ(b)||j-i<SZ(c))continue;
		st[j-i].insert(h.get(i,j));
	}
	ll res=0;
	fore(i,0,SZ(a)+1)res+=SZ(st[i]);
	cout<<res<<"\n";
	return 0;
}
