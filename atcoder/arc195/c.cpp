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

vector<ii> getB(ii s, ll n){
	assert(n%2==0);
	vector<ii>ret;
	fore(i,0,n/2)ret.pb(s),s={s.fst-1,s.snd-1};
	s.fst+=2;
	fore(i,0,n/2)ret.pb(s),s={s.fst+1,s.snd+1};
	return ret;
}
vector<ii> getR(ii s, ll n){
	assert(n%2==0);
	vector<ii>ret;
	fore(i,0,n/2)ret.pb(s),s.snd++;
	s.snd--;
	s.fst--;
	fore(i,0,n/2)ret.pb(s),s.snd--;
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll R,B; cin>>R>>B;
		if((R&1)||((B&1)&&!R)){
			cout<<"No\n";
			continue;
		}
		vector<ii>b,r;
		b=getB({0,0},B^(B&1));
		ii s={2,0};
		if(B&1)b.pb(s),s.fst--,s.snd++;
		r=getR(s,R);
		ll mn=0; for(auto i:b)mn=min({mn,i.fst,i.snd});
		if(B==1)b[0]={0,0};
		cout<<"Yes\n";
		mn=-mn; mn+=3;
		for(auto [i,j]:b)cout<<"B "<<i+mn<<" "<<j+mn<<"\n";
		for(auto [i,j]:r)cout<<"R "<<i+mn<<" "<<j+mn<<"\n";
	}
	return 0;
}
