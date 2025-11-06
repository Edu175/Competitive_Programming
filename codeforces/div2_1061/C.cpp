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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n),oc(n+1);
		fore(i,0,n)cin>>a[i],oc[a[i]]++;
		ll res=1;
		ll p=0,cl=0;
		fore(g,1,n+1){
			while(p<min(4*g,n+1))cl+=oc[p++];
			ll cm=0;
			for(ll i=0;i<min(4*g,n+1);i+=g)cm+=oc[i];
			ll bad=cl-cm;
			// cout<<g<<": "<<cl<<" "<<cm<<": "<<bad<<"\n";
			if(k>=bad)res=g;
		}
		cout<<res<<"\n";
	}
	return 0;
}
