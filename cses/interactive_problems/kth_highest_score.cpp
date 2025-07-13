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

ll n;
ll ask(char c, ll i){
	cout<<c<<" "<<i+1<<endl;
	ll ret; cin>>ret;
	return -ret;
}

int main(){FIN;
	ll k; cin>>n>>k; k--;
	if(k==2*n-1){
		ll ret=-max(ask('F',n-1),ask('S',n-1));
		cout<<"! "<<ret<<"\n";
		return 0;
	}
	auto der=[&](ll d)->bool{// el puntero de abajo (d) esta a la derecha (blanco)
		ll c=k-1-d;
		if(c>=n)return 0;
		return ask('F',c)<ask('S',d);
	};
	ll l=-1,r=min(k-1,n-1)+1; // vamos a hacer (,)
	while(r-l>1){
		ll m=(l+r)/2;
		if(der(m))r=m;
		else l=m;
	}
	ll d=r,c=k-d;
	ll a=c<n?ask('F',c):1;
	ll b=d<n?ask('S',d):1;
	// cout<<c<<" "<<d<<" c d\n";
	cout<<"! "<<-min(a,b)<<"\n";
	return 0;
}
