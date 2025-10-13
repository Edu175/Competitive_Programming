#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll m;
ll f(vv a){
	sort(ALL(a));
	reverse(ALL(a));
	while(SZ(a)&&!a.back())a.pop_back();
	reverse(ALL(a));
	
	if(!SZ(a))return 0;
	
	// ll dbg=a==vv({2,2,6,6});
	
	ll res=100,n=SZ(a);
	fore(i,0,n)if(a[i]<m&&(!i||a[i]!=a[i-1])){
		vv b;
		fore(j,0,n)if(i!=j)b.pb(a[j]);
		res=min(res,1+f(b));
		// if(dbg){
		// 	cout<<"b: ";
		// 	for(auto i:b)cout<<i<<" ";;cout<<"\n";
		// }
		ll c=m-a[i];
		fore(j,0,SZ(b))if(b[j]>=c&&(!j||b[j]!=b[j-1])){
			auto bp=b;
			bp[j]-=c;
			res=min(res,1+f(bp));
			// if(dbg){
			// 	cout<<"bp: ";
			// 	for(auto i:bp)cout<<i<<" ";;cout<<"\n";
			// }
		}
	}
	
	fore(i,0,n)if(a[i]>=m&&(!i||a[i]!=a[i-1])){
		auto b=a;
		b[i]-=m;
		res=min(res,1+f(b));
	}
	// cout<<"f ";;for(auto i:a)cout<<i<<" ";;cout<<": "<<res<<"\n";
	return res;
}

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b>>m;
		if(a>b)swap(a,b);
		if((a>=m&&b>=m)||b>=2*m){
			cout<<(2*(a+b)+m-1)/m<<"\n";
			continue;
		}
		cout<<f({a,a,b,b})<<"\n";
	}
    return 0;
}
