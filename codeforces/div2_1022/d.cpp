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
map<ll,ll>mp;
ll ask(ll i){
	if(mp.count(i))return mp[i];
	cout<<"? "<<i+1<<endl;
	ll ret; cin>>ret;
	mp[i]=ret;
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		mp.clear();
		ll n,k; cin>>n>>k;
		if(2*k==n){
			cout<<"! "<<k<<" "<<k<<endl;
			continue;
		}
		vv a(k),b(k);
		fore(i,0,k)a[i]=ask(i);
		ll s=n-k;
		fore(i,0,k)b[i]=ask(s+i);
		vv md(k);
		fore(i,0,k)md[(s+i)%k]=b[i];
		auto ty=[&](ll i)->ll{
			if(i<k)return 1;
			if(i>=s)return 2;
			ll v=ask(i),r=i%k;
			ll res=(v==a[r])+2*(v==md[r]);
			return res;
		};
		ll rem=-1;
		fore(i,0,k)if(a[i]!=md[i])rem=i;
		if(rem==-1){
			cout<<"! -1"<<endl;
			continue;
		}
		ll l=0,r=n/k;
		while(l<=r){
			ll m=(l+r)/2;
			ll p=m*k+rem,rq=ty(p);
			assert(rq!=3);
			if(rq==1)l=m+1;
			else r=m-1;
		}
		swap(l,r);
		l=l*k+rem;
		r=r*k+rem;
		vv tps;
		fore(i,l,r+1)tps.pb(ty(i));
		vv ps;
		fore(i,0,SZ(tps)-1)if(tps[i]==1&&tps[i+1]==2)ps.pb(l+i);
		assert(SZ(ps)<2);
		ll res=-1;
		cout<<"! ";
		if(SZ(ps))cout<<ps[0]+1<<" "<<n-(ps[0]+1)<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
