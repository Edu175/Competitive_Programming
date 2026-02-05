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

int main(){FIN;
	map<string,ll> mp;
	while(1){
		string s; cin>>s;
		if(s=="pinga")break;
		mp[s]++;
	}
	vector<pair<ll,string>> a;
	for(auto [x,d]:mp)a.pb({-d,x});
	sort(ALL(a));
	for(auto i:a)cout<<"{"<<-i.fst<<",\""<<i.snd<<"\"},\n";
	return 0;
}
