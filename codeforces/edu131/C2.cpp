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
const ll MAXN=200005;
ll n,m;
ll oc[MAXN];

bool solve(ll res){
	ll tks=0;
	ll dif=0;
	fore(i,0,n){
		if(oc[i]>res)tks+=oc[i]-res;
		else dif+=(res-oc[i])/2;
	}
	if(tks-dif<=0)return 1;
	else return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n)oc[i]=0;
		fore(i,0,m){
			ll a; cin>>a; a--;
			oc[a]++;
		}
		ll l=1,r=2*m;
		while(l<=r){
			ll x=(l+r)/2;
			if(solve(x))r=x-1;
			else l=x+1;
		}
		cout<<l<<"\n";
		/*ll q; cin>>q;
		while(q--){
			ll a; cin>>a;
			cout<<solve(a)<<endl;
		}*/
	}
	return 0;
}
