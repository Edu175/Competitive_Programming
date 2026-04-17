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
typedef array<ll,5> tup;

tup merge(tup a, tup b, tup c, vv per){
	tup r; fore(i,0,5)r[i]=0;
	r[0]+=a[0];
	r[0]+=b[0];
	r[0]+=c[0];
	if(per==vv({0,1,2}))
}

int main(){FIN;
	vector<tup> all;
	tup solo; fore(i,0,5)solo[i]=0;; solo[0]=1;
	set<ll> done={1};
	ll N; cin>>N;
	while(SZ(done)<N){
		vv prox;
		fore(i,0,SZ(all))fore(j,0,SZ(all))fore(k,0,SZ(all)){
			vv per(3); iota(ALL(per),0);
			tup cur;
		}
	}
	return 0;
}
