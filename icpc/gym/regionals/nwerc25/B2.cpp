#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
	ll n; cin>>n;
	auto _n=n;
	ll L=n/1000;
	n%=1000;
	auto s=to_string(n);
	// reverse(ALL(s));
	vv ps;
	fore(i,0,SZ(s)){
		if(s[i]!='0'&&s[i]!='4')ps.pb(i);
	}
	if(!SZ(ps)){
		cout<<"splittable\n";
		return 0;
	}
	vv res(2*L,500);
	ll pot=1;
	fore(_,0,SZ(s)-1)pot*=10;
    fore(i,0,SZ(s)){
		vv ds={5,2,1};
		for(auto &i:ds)i*=pot;
		for(auto d:ds)while(n>=d){
			res.pb(d),n-=d;
		}
		pot/=10;
	}
	assert(accumulate(ALL(res),0ll)==_n);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i<<" ";;cout<<"\n";
	return 0;
}