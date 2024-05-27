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
	ll n,m; cin>>n>>m;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst;
	fore(i,0,n)cin>>a[i].snd;
	vector<ii>b;
	fore(i,0,n)b.pb({a[i].snd-a[i].fst,i});
	sort(ALL(b));
	for(auto [w,i]:b){
		if(m>=w)m+=a[i].fst;
		else break;
	}
	cout<<m<<"\n";
	return 0;
}
