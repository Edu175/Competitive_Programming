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
const ll MAXN=1e6+5;

vector<ll> pf[MAXN];
void prime_factors(){
	fore(i,2,MAXN){
		if(!SZ(pf[i])){
			for(ll j=i;j<=MAXN;j+=i)pf[j].pb(i);
		}
	}
}
ll com[MAXN];

int main(){FIN;
	mset(com,0);
	ll n; cin>>n;
	ll a[n];
	prime_factors();
	//ll tle=0;
	fore(i,0,n){
		cin>>a[i];
		vector<ll>&v=pf[a[i]];
		//cout<<i<<" "<<SZ(v)<<"\n";
		//tle+=1ll<<SZ(v);
		fore(m,1,1ll<<SZ(v)){
			ll key=1;
			fore(j,0,SZ(v)){
				if(m&(1ll<<j))key*=v[j];
			}
			com[key]++;
		}
	}
	ll res=(n*(n-1)/2);
	//imp(com);
	//cout<<res<<"\n";
	fore(i,2,MAXN){
		if(com[i]<=1)continue;
		//cout<<i<<" "<<com[i]<<"\n";
		ll add=(com[i]*(com[i]-1))/2;
		if(SZ(pf[i])&1)res-=add;
		else res+=add;
		//imp(pf[i]);
		//cout<<add<<" = "<<res<<"\n\n";
	}
	cout<<res<<"\n";
	//cout<<"opers:  "<<tle<<"\n";
	return 0;
}
