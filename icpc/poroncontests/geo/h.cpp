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

int main(){FIN;
	vector<ii>a(3);
	fore(i,0,3)cin>>a[i].fst>>a[i].snd;
	cout<<fixed<<setprecision(7)<<ld(a[0].fst+a[1].fst+a[2].fst)/3<<" "<<ld(a[0].snd+a[1].snd+a[2].snd)/3<<"\n";
	return 0;
}