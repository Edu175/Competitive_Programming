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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		string x; cin>>x;
		vv bo(n);
		fore(i,0,n)bo[i]=x[i]-'0';
		ll mn=p[0],mx=p[n-1];
		if(!bo[0]&&!bo[n-1]&&!bo[mn]&&!bo[mx]){
			cout<<"5\n";
			mn++,mx++,
			cout<<1<<" "<<mn<<"\n";
			cout<<1<<" "<<mx<<"\n";
			cout<<mn<<" "<<n<<"\n";
			cout<<mx<<" "<<n<<"\n";
			cout<<1<<" "<<n<<"\n";
		}
		else cout<<"-1\n";
	}
	return 0;
}
