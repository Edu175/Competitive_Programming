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

const ll B=32;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vv a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		for(ll j=B-1;j>=0;j--){
			if(j<=4){
				imp(a);
			}
			vector<ii>ch;
			fore(i,0,n){
				ll mn=a[i];
				fore(l,0,m)mn=min(mn,a[i]&b[l]);
				ch.pb({a[i]-mn,i});
			}
			sort(ALL(ch)); reverse(ALL(ch));
			for(auto [d,i]:ch)if(k>0&&(d>>j&1)){
				a[i]-=d,k--;
				cout<<j<<": ";
				cout<<"bajo "<<i<<": "<<d<<"\n";
			}
		}
		ll sum=0;
		fore(i,0,n)sum+=a[i];
		cout<<sum<<"\n";
	}
	return 0;
}
