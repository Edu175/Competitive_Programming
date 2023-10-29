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
const ll MOD=998244353;

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll B=32;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),xp(n+1);
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1];
	ll res=0,men=0;
	//imp(xp);
	vector<vector<ll>> oc(n+1,vector<ll>(B)); // ] on xp
	fore(i,1,n+1){
		fore(j,0,B){
			oc[i][j]=oc[i-1][j];
			if(xp[i]&(1ll<<j))oc[i][j]++;;
		}
	}
	fore(i,0,n+1){
		vector<ll>pre(B),suf(B);
		if(i)pre=oc[i-1];
		suf=oc[n];
		fore(j,0,B)suf[j]-=oc[i][j];
		//cout<<i<<": "<<pre<<" "<<suf<<"\n";
		fore(j,0,B){
			if(xp[i]&(1ll<<j)){
				res=(res+(1ll<<j)*(i-pre[j])%MOD*i)%MOD;
				men=(men+(1ll<<j)*(n-i-suf[j])%MOD*i)%MOD;
			}
			else {
				res=(res+(1ll<<j)*pre[j]%MOD*i)%MOD;
				men=(men+(1ll<<j)*suf[j]%MOD*i)%MOD;
			}
		}
	}
	cout<<(res-men+MOD)%MOD<<"\n";
	return 0;
}
