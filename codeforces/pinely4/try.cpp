#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXV=2e5+5;

ll cr[MAXV];

int main(){FIN;
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]==-1)for(ll j=1ll*i*i;j<MAXV;j+=i)
		cr[j]=i;
	cr[0]=cr[1]=1;
	vector<ll>ps;
	vector<ii>tw;
	fore(i,2,MAXV)if(cr[i]==-1){
		ps.pb(i);
		if(cr[i-2]==-1)tw.pb({i-2,i});
	}
	cout<<SZ(ps)<<"\n";
	cout<<SZ(tw)<<"\n";
	for(auto i:tw)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	return 0;
}