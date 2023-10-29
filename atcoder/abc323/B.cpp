#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	string a[n];
	vector<ii>pos;
	fore(i,0,n){
		cin>>a[i];
		ll cnt=0;
		fore(j,0,n)cnt+=a[i][j]=='o';
		pos.pb({cnt,-i});
	}
	sort(ALL(pos)); reverse(ALL(pos));
	for(auto i:pos)cout<<-i.snd+1<<" ";
	cout<<"\n";
	return 0;
}
