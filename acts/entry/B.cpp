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

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
vector<ii>dir={{1,0},{0,1},{-1,0},{0,-1}};
ll n;
bool allowed(ii a){
	return a.fst>=0&&a.fst<n&&a.snd>=0&&a.snd<n;
}
int main(){FIN;
	fore(i,0,2)fore(j,0,2)dir.pb({i*2-1,j*2-1});
	ll m; cin>>n>>m;
	ll a[n][n]; mset(a,0);
	fore(_,0,m){
		ii p; cin>>p.fst>>p.snd; p.fst--,p.snd--;
		for(auto d:dir)for(auto i=p;allowed(i);i=i+d)a[i.fst][i.snd]=1;
	}
	ll res=n*n;
	fore(i,0,n)fore(j,0,n)res-=a[i][j];
	cout<<res<<"\n";
	return 0;
}
