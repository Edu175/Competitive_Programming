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

vector<pair<ll,string>> us={
{11,"UW"},
{9,"UJ"},
{8,"UWR"},
{7,"MAP"},
{6,"PW"},
{5,"AGH"},
{4,"PG"},
{3,"NLU"},
{3,"PUT"},
{2,"PO"},
{2,"PWR"},
{2,"SGGW"},
{2,"UMCS"},
{2,"UR"},
{2,"ZUT"},
{1,"DTP"},
{1,"GOO"},
{1,"HUA"},
{1,"KUL"},
{1,"PL"},
{1,"PM"},
{1,"PS"},
{1,"UAM"},
{1,"UG"},
{1,"UMK"},
{1,"UO"},
{1,"WAT"}
};

int main(){FIN;
	ll n=8,m=10;
	vector<string> all;
	for(auto [c,s]:us)fore(_,0,c)all.pb(s);
	assert(SZ(all)==n*m);
	vector<vector<string>> a(n,vector<string>(m));
	ll cnt=0;
	fore(pi,0,2)fore(pj,0,2)fore(i,0,n/2)fore(j,0,m/2){
		a[2*i+pi][2*j+pj]=all[cnt++];
	}
	string wh; cin>>wh;
	ll pi=-1,pj=-1;
	fore(i,0,n)fore(j,0,m){
		fore(di,-1,2)fore(dj,-1,2)if(!(di==0&&dj==0)){
			ll pi=(i+di+n)%n;
			ll pj=(j+dj+m)%m;
			assert(a[i][j]!=a[pi][pj]);
		}
		if(a[i][j]==wh)pi=i,pj=j;
	}
	rotate(a.begin(),a.begin()+pi,a.end());
	fore(i,0,n){
		rotate(a[i].begin(),a[i].begin()+pj,a[i].end());
	}
	fore(i,0,n){
		fore(j,0,m)cout<<a[i][j]<<" \n"[j==m-1];
	}
	return 0;
}
