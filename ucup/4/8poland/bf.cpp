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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n;
ll res=0;
void f(ll au, ll u, ll c, ll cant){ // c: already placed stuff
	if(u!=-1){
		cant*=c-(au==u); // ways of placing u
	}
	cout<<au<<" "<<u<<": "<<c<<" "<<cant<<"\n";
	if(c>0)res+=cant;
	fore(v,1,n+1){
		if(u!=-1&&u>v)continue;
		if(au!=-1&&au+u>v)continue;
		f(u,v,c+1,cant);
	}
}

int main(){FIN;
	ll N; cin>>N;
	fore(_n,3,N+1){
		n=_n;
		res=0;
		f(-1,-1,0,1);
		cout<<res<<", ";
	}
	cout<<"\n";
	return 0;
}
