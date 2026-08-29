#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

bool valid(vv b){
	ll n=SZ(b);
	vv pos(n+1,-1);
	fore(i,0,n)pos[b[i]]=i;
	if(pos[1]==-1)return 0;
	ll s=pos[1];
	fore(i,s,n)if(b[i]!=i-s+1)return 0;
	ll pr=b.back()+1;
	if(pr>n)return 1;
	ll deb=-1;
	fore(v,pr,n+1){
		if(pos[v]>deb)return 0;
		deb++;
	}
	return 1;
}
vv av(vv b, ll k){
	ll n=SZ(b);
	if(k>=n)return vv(n,0);
	b=vv(b.begin()+k,b.end());
	b.resize(n,0);
	return b;
}
bool can(vv b, ll k){
	b=av(b,k);
	if(count(ALL(b),1))return 0;
	b.pb(1);
	b.erase(b.begin());
	return valid(b);
}

int main(){
	JET
	ll n; cin>>n;
	vv asd(n),b(n);
	fore(i,0,n)cin>>asd[i];
	fore(i,0,n)cin>>b[i];
	if(valid(b)){
		ll p=find(ALL(b),1)-b.begin();
		cout<<p<<"\n";
		// cerr<<"de una\n";
		return 0;
	}
	// show(b)
	ll l=-1,r=2*n;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(b,m))r=m;
		else l=m;
	}
	// cerr<<res<<" "<<r<<"\n";
	ll res=r+n;
	cout<<res<<"\n";
	return 0;
}