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
		a.pb({x,y});
	}
	sort(ALL(a));
	set<ll>st;
	fore(i,0,n){
		ll x=a[i].snd;
		auto lwb=st.lower_bound(x);
		if(lwb!=st.end())st.erase(lwb);
		st.insert(x);
	}
	cout<<SZ(st)<<"\n";
	return 0;
}
