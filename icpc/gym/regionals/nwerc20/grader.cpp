#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=1e6;
ll sq(ll x){return x*x;}
ll dis(ii a, ii b){
	return sq(b.fst-a.fst)+sq(b.snd-a.snd);
}
int main(){
	JET
	vector<ii> a={{4,3}};
	ll n=SZ(a);
	cout<<n<<endl;
	while(SZ(a)){
		// cerr<<"grader: ";
		// for(auto i:a)cerr<<i.fst<<","<<i.snd<<" ";;cerr<<endl;
		ii po; cin>>po.fst>>po.snd;
		ll p=0;
		fore(i,1,n)if(dis(a[i],po)<dis(a[p],po))p=i;
		ll d=dis(a[p],po);
		cout<<d<<endl;
		if(d==0)a.erase(a.begin()+p);
	}
}