#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end();
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv c(2);
	string s; cin>>s;
	for(auto i:s)c[i-'0']++;
	c[0]-=n;c[1]-=2*n;
	if(min(c[0],c[1])<0)cout<<"NIE\n";
	else {
		string res;
		vv w={15,7,3,1};
		ll s=c[0]-c[1],fg=s>0; s=abs(s);
		fg*=3;
		fore(i,0,s/3)res.pb(w[0^fg]);
		fore(i,0,s%3)res.pb(w[1^fg]);
		if(SZ(res)>n)cout<<"NIE\n";
		else {
			while(SZ(res)<n)res.pb(w[1]),res.pb(w[2]);
			for(auto &i:res)i+='a'-1;
			cout<<res<<"\n";
		}
	}
	return 0;
}