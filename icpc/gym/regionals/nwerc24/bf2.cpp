#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// typedef array<ll,3> tri;
typedef array<array<ll,3>,3> mat;
vector<vector<vv>> base={
	{{0, 2, 1},
	{2, 1, 0},
	{1, 0, 2}},

	{{1, 0, 2},
	{2, 1, 0},
	{0, 2, 1}},

	{{1, 1, 1},
	{1, 1, 1},
	{1, 1, 1}},

	{{1, 2, 0},
	{0, 1, 2},
	{2, 0, 1}},

	{{2, 0, 1},
	{0, 1, 2},
	{1, 2, 0}}
};
const ll MX=60;
set<mat> all[MX];
mat cur;
void f(ll p, ll s){
	// cout<<"f "<<p<<" "<<s<<":\n";
	// fore(i,0,3)fore(j,0,3)cout<<cur[i][j]<<" \n"[j==2];
	// cout<<"\n";
	if(p==SZ(base)){all[s].insert(cur);return;}
	fore(c,0,MX){
		ll si=s+c*3;
		if(si>=MX)break;
		fore(i,0,3)fore(j,0,3)cur[i][j]+=c*base[p][i][j];
		f(p+1,si);
		fore(i,0,3)fore(j,0,3)cur[i][j]-=c*base[p][i][j];
	}
}
int main(){
	JET
	f(0,0);
	fore(s,0,MX){
		auto v=all[s];
		cout<<"sum "<<s<<": "<<SZ(v)<<"\n";
		for(auto &a:v){
			fore(i,0,3)fore(j,0,3)cout<<a[i][j]<<" \n"[j==2];
			cout<<"\n";
		}
		cout<<"\n\n";
	}
	return 0;
}