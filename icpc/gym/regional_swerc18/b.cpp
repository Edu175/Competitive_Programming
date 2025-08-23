#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((ll)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll get(pair<vv,vv> lr){ // [,]
	auto [l,r]=lr;
	ll n=SZ(l);
	ll res=0;
	fore(i,0,n){
		ll lo=-1,hi=r[i]-l[i]+1;
		while(hi-lo>1){
			ll k=(lo+hi)/2;
			bool can=i+k<n;
			if(can){
				can&=l[i]+k<=r[i];
				can&=l[i]+k<=r[i+k];
				can&=l[i]>=l[i+k];
			}
			if(can)lo=k;
			else hi=k;
		}
		ll k=lo;
		res=max(res,k);
	}
	return res+1;
}

pair<vv,vv> hor(pair<vv,vv> lr){
	auto [l,r]=lr;
	fore(i,0,SZ(l))swap(l[i],r[i]),l[i]*=-1,r[i]*=-1;
	return {l,r};
}
pair<vv,vv> ver(pair<vv,vv> lr){
	auto [l,r]=lr;
	reverse(ALL(l));
	reverse(ALL(r));
	return {l,r};
}

int main(){
    JE
	ll n; cin>>n;
	vv l(n),r(n);
	fore(i,0,n)cin>>l[i]>>r[i];
	pair<vv,vv> lr={l,r};
	ll res=0;
	fore(i,0,2)fore(j,0,2){
		auto now=lr;
		if(i)now=hor(now);
		if(j)now=ver(now);
		res=max(res,get(now));
	}
	cout<<res<<"\n";
    return 0;
}