#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void cv(ll &x, ll v){
	x*=6/(v+1);
}

int main(){FIN;
	ll v,k; cin>>v>>k; cv(k,v);
	
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n){
		cin>>v>>a[i];
		cv(a[i],v);
		assert(a[i]%(v+1)==0);
	}
	ll r=0,s=0,res=n;
	fore(i,0,n){
		while(r<n&&s<k)s+=a[r++];
		if(s>=k)res=min(res,r-i);
		s-=a[i];
	}
	assert(res>=0);
	cout<<res<<"\n";
	return 0;
}
