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
ll MOD,ME;
const ll MAXV=1e6+5;

int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
map<ll,ll> fact(ll n){  // must call init_cribe before		O(log(n))
	map<ll,ll> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll x,q; cin>>x>>q>>MOD;
	ME=MOD-1;
	init_sieve();
	map<ll,ll>mp;
	//cout<<x<<"\n";
	for(ll i=2;i*i<=x;i++){
		//cout<<i<<" "<<x<<"\n";
		ll c=0;
		while(x%i==0)c++,x/=i;
		if(c)mp[i]=c%ME;
	}
	if(x>1)mp[x]=1;
	__int128 res=1;
	for(auto i:mp){
		if(i.fst!=2)res=res*(i.snd+1)%MOD;
	}
	//for(auto i:mp)cout<<i.fst<<","<<i.snd<<" ";
	//cout<<"\n";
	//cout<<res<<"\n";
	map<ll,ll>z;
	ll cz=0;
	while(q--){
		ll xi; cin>>xi;
		map<ll,ll>mi=fact(xi);
		for(auto i:mi){
			if(i.fst!=2){
				if(z[i.fst])z[i.fst]=0,cz--;
				else res=res*fpow(mp[i.fst]+1,MOD-2)%MOD; //saco
				mp[i.fst]+=i.snd;
				if((mp[i.fst]+1)%MOD==0)z[i.fst]=1,cz++;
				else res=res*(mp[i.fst]+1)%MOD; //pongo
			}
			//else mp[i.fst]+=i.snd;
		}
		//for(auto i:mp)cout<<i.fst<<","<<i.snd<<" ";
		//cout<<"\n";
		ll resi=res;
		//if(mp[2])resi=resi*2%MOD;
		if(cz)cout<<"0\n";
		else cout<<resi<<"\n";
	}
	return 0;
}
