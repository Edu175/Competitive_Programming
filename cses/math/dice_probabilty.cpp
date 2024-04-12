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

int main(){FIN;
	ll n,a,b; cin>>n>>a>>b;
	vector<ld>p(n*6+5);
	p[0]=1;
	fore(_,0,n){
		vector<ld>pi(n*6+5);
		fore(i,0,SZ(p))fore(j,1,7){
			if(i-j>=0)pi[i]+=p[i-j]/6.0;
		}
		p=pi;
	}
	ld res=0;
	fore(i,a,b+1)res+=p[i];
	//res=75e-7;
	//cout<<fixed<<setprecision(15)<<res<<"\n";
	string s=to_string(res);
	cout<<s<<"\n";
	return 0;
}
