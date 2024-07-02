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
	#ifdef ONLINE_JUDGE
    freopen("enchanted.in","r",stdin);     freopen("enchanted.out","w",stdout);
    #endif
	string a,b,c,d; cin>>a>>b>>c>>d;
	reverse(ALL(b)); reverse(ALL(d));
	vector<ii>va;
	fore(i,0,SZ(a))va.pb({a[i],b[i]});
	vector<ii>vc;
	fore(i,0,SZ(c))vc.pb({c[i],d[i]});
	sort(ALL(va)); sort(ALL(vc));
	if(va==vc)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}