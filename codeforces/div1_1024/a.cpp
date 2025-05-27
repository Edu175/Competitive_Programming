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
vector<ii> dir={{0,1},{1,0},{0,-1},{-1,0}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vv>a(n,vv(n));
		ii x={(n+1)/2-1,-1}; x.snd=x.fst;
		ll d=0,am=1,cnt=0;
		while(x.fst<n&&x.fst>=0&&x.snd<n&&x.snd>=0){
			fore(i,0,am){
				a[x.fst][x.snd]=cnt++;
				x=x+dir[d];
			}
			d=(d+1)%4;
			if(d%2==0)am++;
		}
		fore(i,0,n){
			fore(j,0,n)cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
