#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ii,ll>>a(n);
	fore(i,0,n)cin>>a[i].fst.snd>>a[i].fst.fst,a[i].snd=i;
	sort(ALL(a));
	vector<ii>b={a[0].fst};
	vector<ll>r={a[0].snd};
	fore(i,1,n){
		if(b.back().snd<a[i].fst.snd)b.pb(a[i].fst),r.pb(a[i].snd);
	}
	sort(ALL(r));
	cout<<SZ(r)<<"\n";
	for(auto i:r)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
