#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int consulta(int i,int W,int H);

int rectangulos(vector<int> x, vector<int> y) {
	ll n=SZ(x);
	vector<pair<ii,ll>>b;
	fore(i,0,n)b.pb({{x[i],y[i]},i});
	sort(ALL(b));
	vector<vector<pair<ii,ll>>>a;
	fore(i,0,n){
		if(!i||b[i].fst.fst!=b[i-1].fst.fst)a.pb({b[i]});
		else a.back().pb(b[i]);
	}
	//flatten
	while(SZ(a)>1){
		ll c=0,v=0,s=0;
		fore(i,0,SZ(a)){
			s+=SZ(a[i]);
			if(abs(n/2-s)<=abs(n/2-v))c=i,v=s;
		}
		ll d=a[c][0].fst.fst-a[0][0].fst.fst;
		d=max((ll)1,2*abs(d));
		vector<vector<pair<ii,ll>>>ai; n=0;
		if(consulta(a[0][0].snd+1,d,2e9))fore(i,0,c+1)ai.pb(a[i]),n+=SZ(a[i]);
		else fore(i,c+1,SZ(a))ai.pb(a[i]),n+=SZ(a[i]);
		a=ai;
	}
	//column
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		ll d=a[0][m].fst.snd-a[0][0].fst.snd;
		d=max((ll)1,2*abs(d));
		if(consulta(a[0][0].snd+1,2e9,d))r=m-1;
		else l=m+1;
	}
	return a[0][l].snd+1;
}
