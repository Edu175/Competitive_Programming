#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ifstream cin;   cin.open("mesadas.in", ios::in);
	ofstream cout; cout.open("mesadas.out", ios::out);
	ll n; cin>>n;
	vector<ii>a;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		if(x>y)swap(x,y);
		y*=-1;
		a.pb({x,y});
	}
	sort(ALL(a));
	vector<ll>b;
	fore(i,0,n){
		ll x=a[i].snd;
		ll w=lower_bound(ALL(b),x)-b.begin();
		if(w>=SZ(b))b.pb(x);
		else b[w]=x;
	}
	cout<<SZ(b)<<"\n";
	return 0;
}
