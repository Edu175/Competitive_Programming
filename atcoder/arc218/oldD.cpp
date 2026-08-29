#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

void solve(vv a){
	ll n=SZ(a);
	ii bst={-1,0};
	fore(mk,1,1ll<<n){
		ll prev=1e9,inc=0,sz=0;
		fore(i,0,n)if(mk>>i&1){
			inc+=prev<a[i];
			prev=a[i];
			sz++;
		}
		ii cur={inc,-sz};
		bst=max(bst,cur);
	}
	cout<<-bst.snd<<"\n";
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv all;
	fore(i,0,n){
		if(i&&i+1<n&&a[i-1]>a[i]&&a[i]>a[i+1])continue;
		all.pb(i);
	}
	auto cuan=[&](ll l, ll r){ // [,)
		return lower_bound(ALL(all),r)-lower_bound(ALL(all),l);
	};
	vv bad(n),has(n);
	fore(idx,0,SZ(all)){
		ll i=all[idx];
		if(idx&&idx+1<SZ(all)){
			ll l=all[idx-1];
			ll r=all[idx+1];
			if(!(a[l]<a[i]&&a[i]<a[r])&&a[l]<a[r])bad[i]=1;
		}
	}
	vv ant(n,-1),sig(n,-1);
	fore(idx,0,SZ(all)){
		ll i=all[idx];
		if(idx){
			ll l=all[idx-1];
			ant[i]=l;
			sig[l]=i;
		}
		if(bad[i]){
			has[i]=1;
			if(idx){
				if(has[ant[i]])has[i]=0;
			}
		}
	}
	show(all)
	show(bad)
	vv blo(n,-1),od(n,-1),rs(n),ls(n);
	ll cnt=0,co=0;
	vv bl;
	for(auto i:all){
		bl.pb(i);
		od[i]=co; co^=1;
		blo[i]=cnt;
		if(sig[i]==-1||bad[i]!=bad[sig[i]]){
			for(auto j:bl)rs[j]=i,ls[j]=bl[0];
			bl.clear();
			cnt++;
		}
	}
	vv sp(n+1); fore(i,1,n+1)sp[i]=sp[i-1]+has[i-1];
	show(bad)
	show(has)
	#define UNIT if(l>=r){\
					cout<<"1\n";\
					continue;\
				}
	while(q--){
		ll l,r; cin>>l>>r; l--; r--;
		l=*lower_bound(ALL(all),l);
		r=*lower_bound(ALL(all),r);
		UNIT
		if(a[l]>a[sig[l]])l=sig[l];
		UNIT
		if(a[ant[r]]>a[r])r=ant[r];
		UNIT
		cerr<<"query "<<l<<","<<r<<"\n";
		ll z=cuan(l,r+1);
		if(z==2){
			cout<<1+(a[l]<a[r])<<"\n";
			continue;
		}
		// if(z<=4){
		// 	vv b;
		// 	for(ll i=l;i!=-1&&i<=r;i=sig[i])b.pb(a[i]);
		// 	solve(b);
		// 	continue;
		// }
		assert(z>=3);
		ll tok=sp[r]-sp[l+1];
		ll dobl=bad[l]&&bad[sig[l]];
		ll dobr=bad[r]&&bad[ant[r]];
		ll same=blo[l]==blo[r];
		if(same){
			assert(dobl==dobr);
			tok+=dobl&&od[l]==od[r]&&has[l];
		}
		else {
			tok+=dobl&&has[l]&&od[l]!=od[rs[l]];
			tok+=dobr&&has[r]&&od[r]!=od[ls[r]];
		}
		// cerr<<z<<" "<<tok<<": ";
		ll res=z-tok;
		cout<<res<<"\n";
	}
	return 0;
}
