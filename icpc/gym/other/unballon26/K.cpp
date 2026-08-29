#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
string at="FGW";
ll get(char c){return at.find(c);}

int main(){FIN;
	char ta,td; cin>>ta>>td;
	ll a=get(ta),d=get(td);
	ll p; cin>>p;
	ll h; cin>>h;
	ll m=d==(a+1)%3?4:1;
	ll res=max(0ll,h-p*m/2);
	if(!res){
		cout<<"Nocaute!\n";
	}
	else {
		printf("Sobraram %lld pontos de vida!\n",res);
	}
	return 0;
}
