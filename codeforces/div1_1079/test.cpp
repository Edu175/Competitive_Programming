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

bool valid(ll c, ll s){
	ll k=s/c, r=s%c;
	vv a(c,k); if(r)a.back()=r;
	while(SZ(a)){
		sort(ALL(a)); reverse(ALL(a));
		// if(a.back()<0)return 0;
		while(SZ(a)&&!a.back())a.pop_back();
		if(!SZ(a))return 1;
		ll d=a[0];
		a[0]=0;
		if(d+1>SZ(a))return 0;
		fore(i,1,d+1)a[i]--;
	}
	assert(0);
	
}

int main(){FIN;
	ll N; cin>>N;
	fore(n,8,N+1){
		cerr<<n<<"\n";
		cout<<n<<": ";
		ll M=n*(n-1)/2+1;
		vv good(M);
		
		fore(k,1,n)fore(m,k+1,M){
			ll s=2*m;
			if(!(s<=n*k))continue;
			ll c=(s+k-1)/k;
			if(k>=c)continue;
			if(!valid(c,s))continue;
			if(s%k||s/k%2)good[m]=1;
		}
		
		cout<<"failed: ";
		fore(i,1,M)if(!good[i])cout<<i<<" ";
		cout<<", ";
		ll last=M-1;
		cout<<"last "<<last<<"\n";
		ll cnt=count(ALL(good),0ll)-!good[0];
		ll d=n/2;
		// if(n%2==0){
		// 	assert(cnt==7);
		// 	assert(!good[last]);
		// 	assert(!good[last-d]);
		// }
		// else {
		// 	assert(cnt==8);
		// 	assert(!good[last-d]);
		// 	assert(!good[last-2*d]);
		// 	assert(!good[last-3*d]);
		// }
	}
	return 0;
}
