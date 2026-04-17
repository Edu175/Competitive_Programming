#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=4000;
ll n;
ll qidx=0;
int g[MAXN][255];
int mem[255][255][255];
bool vis[255][255][255];

ll f(ll l, ll r, ll cnt){
	auto &res=mem[l][r][cnt];
	auto &vi=vis[l][r][cnt];
	// assert(!vi);
	if(vi)return res;
	vi=1;
	// assert(cnt<r-l);
	if(cnt>=(r-l))return 0;
	if(r-l==1)return -l;
	ll me=qidx++;
	// cerr<<"f "<<l<<","<<r<<" "<<cnt<<": "<<me<<"\n";
	ll m=(l+r)/2;
	fore(v,1,n){
		if(l<=v&&v<m){
			g[me][v]=f(l,r,cnt+1);
		}
		else {
			g[me][v]=me;
		}
	}
	if(cnt<m-l){
		g[me][0]=f(l,m,0);
	}
	else {
		g[me][0]=f(m,r,0);
	}
	return res=me;
}

int main(){
	JET
	cin>>n; n+=2;
	f(1,n,0);
	assert(qidx<=MAXN);
	cout<<qidx<<"\n";
	fore(i,0,qidx){
		fore(j,0,n)cout<<g[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}