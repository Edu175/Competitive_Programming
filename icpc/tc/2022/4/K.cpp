#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

const ll MAXN=1005;
bool isP[MAXN];
vector<ll>prim;

void criba(){
	isP[0]=isP[1]=0;
	fore(i,2,MAXN)iP[i]=1
	fore(p,2,MAXN){
		if(iP[p]){
			for(ll m=2*p; m<MAXN; m+=p)iP[m]=0;
		}
	}
	fore(i,0,MAXN){
		if(iP[i])prim.pb(i);
	}
}

vector<pair<ll,ll> fact(ll x){
	vector<ll>res
	for(ll i=0; prim[i]*prim[i]<=x&&i<MAXN; i++){
		ll c=0;
		while(x%prim[i]==0){
			c++;
			x/=prim[i];
		}
		if(c)res.pb({prim[i],c});
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	ll flag=0;
	fore(i,0,n){
		cin>>a[i];
		ll isev=1;
		for(auto j:fact(a[i])){
			if(j.snd%2)isev=0;
			else
		}
		if(isev)flag=1;
	}
	return 0;
}






