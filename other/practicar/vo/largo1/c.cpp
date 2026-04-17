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
const ll INF=1e16;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv b={0};
	fore(i,0,k)b.back()+=a[i];
	fore(i,k,n)b.pb(b.back()-a[i-k]+a[i]);
	set<ii>r;
	ii mx={-1,1};
	fore(i,0,SZ(b))r.insert({b[i],-i});
	ll p=-1,q=-1,score=-1;
	auto cand=[&](ll i, ll j, ll s){
		// cout<<"cand "<<i<<" "<<j<<" "<<s<<endl;
		assert(j-i>=k);
		if(s>score)score=s,p=i,q=j;
		else if(s==score){
			if(ii({i,j})<ii({p,q}))p=i,q=j;
		}
	};
	fore(i,0,SZ(b)){
		if(i-k>=0)mx=max(mx,ii({b[i-k],-(i-k)}));
		if(mx.fst!=-1){
			auto [s,p]=*r.rbegin();
			cand(-mx.snd,-p,mx.fst+s);
		}
		r.erase({b[i],-i});
	}
	cout<<p+1<<" "<<q+1<<"\n";
	return 0;
}