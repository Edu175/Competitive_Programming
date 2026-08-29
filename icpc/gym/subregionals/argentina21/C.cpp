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

int main(){FIN;
	ll B,n; cin>>B>>n; ll M=B+1;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	reverse(ALL(a));
	ll sum=0;
	fore(i,0,n)sum+=(i%2==0?a[i]:-a[i]);
	if(sum%M==0){
		cout<<"0 0\n";
		return 0;
	}
	ii ans={-1,-1};
	fore(i,0,n){
		ll cur=sum;
		cur-=(i%2==0?a[i]:-a[i]);
		cur%=M;
		ll deb=-1,did=0;
		fore(sig,0,2){
			ll cand=cur; if(sig)cand*=-1;
			if((cur+(i%2==0?cand:-cand))%M==0)deb=cand,did=1;
		}
		assert(did);
		deb+=M; deb%=M;
		if(deb<a[i]){
			ans={i,deb};
		}
	}
	if(ans.fst==-1){
		cout<<"-1 -1\n";
		return 0;
	}
	auto [p,v]=ans;
	p=n-p;
	cout<<p<<" "<<v<<"\n";
	return 0;
}
