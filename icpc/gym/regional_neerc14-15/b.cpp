#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
// typedef long long ld;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-10;
int main(){
	
	#ifdef ONLINE_JUDGE
	freopen("burrito.in","r",stdin);     freopen("burrito.out","w",stdout);
	#endif

	JET
	ll n,A,B; cin>>n>>A>>B;
	vector<array<ll,3>>h(n);
	fore(i,0,n)cin>>h[i][2]>>h[i][0]>>h[i][1];
	vv per(n); iota(ALL(per),0);
	sort(ALL(per),[&](ll i, ll j){
		auto &a=h[i],b=h[j];
		return a[0]*b[1]>b[0]*a[1];
	});
	
	// sort(ALL(h),[&](array<ll,3> a, array<ll,3> b){
	// 	return a[0]*b[1]>b[0]*a[1];
	// });
	ld sa=0,sb=0;
	vector<ld> ans(n);
	auto good=[&](){return A<=sa+EPS&&sb-EPS<=B;};
	for(auto i:per){
		auto [a,b,g]=h[i];
		ld s;
		if(sb+g*b<=B){
			s=g;
			// ans.pb(g);
		}
		else {
			s=(B-sb)/b;
			if(abs(s)<=EPS)s=0;
		}
		ans[i]=s;
		sa+=s*a;
		sb+=s*b;
	}
	if(!good())cout<<"-1 -1\n";
	else {
		cout<<fixed<<setprecision(15);
		cout<<sa<<" "<<sb<<"\n";
		for(auto i:ans)cout<<i<<" ";;cout<<"\n";
	}
	return 0;
	
}