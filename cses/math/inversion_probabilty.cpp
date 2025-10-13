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
typedef long double ld;
typedef pair<ll,ll> ii;
const ld EPS=1e-8;

ld out(ld x){
	ld y=x*1e6;
	cerr<<fixed<<setprecision(10)<<y<<"\n";
	ld r=remainder(y,1);
	y-=r; // truncado
	if(abs(r-0.5)<EPS){
		cerr<<"exactly half\n";
		if(ll(y)%2==1)y++;
		// y++;
	}
	else if(r>0.5)y++;
	return y/1e6;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ld>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ld>p(105);
	ld res=0;
	for(ll i=n-1;i>=0;i--){
		fore(j,0,a[i]){
			fore(k,0,j)res+=p[k]/a[i];
		}
		fore(j,0,a[i])p[j]+=1./a[i];
	}
	cout<<fixed<<setprecision(6)<<out(res)<<"\n";
	//cout<<to_string(res)<<"\n";
	return 0;
}
