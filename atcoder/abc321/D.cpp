#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m,p;
	cin>>n>>m>>p;
	vector<ll>a(n),b(m),sp(n+1);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	sort(ALL(a));
	sort(ALL(b));
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	ll res=0;
	fore(i,0,SZ(b)){
		ll pos=lower_bound(ALL(a),p-b[i])-a.begin();
		res+=sp[pos]+b[i]*pos+(n-pos)*p	;
		//cout<<i<<" "<<pos<<": "<<sp[pos]*b[i]+(n-pos)*p<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
