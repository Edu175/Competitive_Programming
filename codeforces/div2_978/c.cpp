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
const ll MAXN=1e5+5,INF=MAXN*5;

ll n;
char a[MAXN][2];
ll val(char a, char b, char c){
	string s;
	s.pb(a);
	s.pb(b);
	s.pb(c);
	if(count(ALL(s),'A')>=2)return 1;
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(h,0,2)fore(i,0,n)cin>>a[i][h];
		ll res=0;
		for(ll i=0;i<n;i+=3){
			ll resi=0;
			ll c=val(a[i][0],a[i+1][0],a[i+2][0])+
				 val(a[i][1],a[i+1][1],a[i+2][1]);
			resi=max(resi,c);
			c=val(a[i][0],a[i][1],a[i+1][0])+
			  val(a[i+1][1],a[i+2][0],a[i+2][1]);
			resi=max(resi,c);
			c=val(a[i][0],a[i][1],a[i+1][1])+
			  val(a[i+1][0],a[i+2][0],a[i+2][1]);
			resi=max(resi,c);
			res+=resi;
		}
		cout<<res<<"\n";
	}
	return 0;
}
