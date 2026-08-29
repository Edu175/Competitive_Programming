#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll x;
ll qused;

#ifndef ONLINE_JUDGE
ll M;
#endif

ll ask(ll t){
	++qused;
	// assert(qused<=105);
	#ifdef ONLINE_JUDGE
	cout<<"? "<<t<<endl;
	#endif
	string ret;
	#ifndef ONLINE_JUDGE
	if(t>1e14)ret="Fired!";
	else if(t>M)ret="Fraudster!";
	else ret="Lucky!";
	#else
	cin>>ret;
	#endif
	if(ret=="Fired!")exit(0);
	if(ret=="Lucky!"){
		x+=t;
		return 1;
	}
	x-=t;
	return 0;
}

ll lgt(ll n){return n==1?0:__lg(n-1)+1;}

ll getm(ll l, ll r){
	if(x>(r-1)*(lgt(r-l)+5)/2)return (l+r)/2;
	return l+ceil((r-l)*0.3217);
}

void calc(ll l, ll r){
	while(r-l>1){
		ll m=getm(l,r);
		while(x<l+m)ask(l);
		if(!ask(m))r=m;
		else l=m;
	}
	cout<<"! "<<l<<endl;
}
const ll MAXM=1e14;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		#ifndef ONLINE_JUDGE
		cin>>M;
		#endif
		qused=0,x=1;
		ll l=0;
		while(l<MAXM){
			ll r=!l?1:2*l;
			r=min(r,MAXM);
			// cerr<<l<<","<<r<<"\n";
			if(!ask(r)){calc(l,r);break;}
			l=r;
		}
		if(l==MAXM)calc(l,l+1);
		#ifndef ONLINE_JUDGE
		cerr<<"queries used: "<<qused<<"\n";
		#endif
	}
	return 0;
}