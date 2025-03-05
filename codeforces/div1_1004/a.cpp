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

ll ask(ll i, ll j){
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vv deg(n);
		fore(i,0,n)cin>>a[i],a[i]--,deg[a[i]]++;
		ll x=-1;
		fore(i,0,n)if(!deg[i])x=i;
		if(x!=-1){
			ll y=0+(x==0);
			if(ask(x,y)==0)cout<<"! A"<<endl;
			else cout<<"! B"<<endl;
			continue;
		}
		ll mn=0,mx=0;
		fore(i,0,n){
			
			if(a[i]<a[mn])mn=i;
			if(a[i]>a[mx])mx=i;
		}
		ll sum=ask(mn,mx)+ask(mx,mn);
		if(sum>=2*n-2)cout<<"! B"<<endl;
		else cout<<"! A"<<endl;
	}
	return 0;
}
