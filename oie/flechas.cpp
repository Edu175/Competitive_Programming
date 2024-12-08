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
const ll MAXN=2005;


ll n;
char a[MAXN][MAXN];
ll lrow[MAXN],rrow[MAXN];
ll lcol[MAXN],rcol[MAXN];
ll is[MAXN][MAXN];
queue<ii>q;
void evaluoR(ll i){
	auto &l=lrow[i];
	auto &r=rrow[i];
	while(l<=r&&!is[i][l])l++;
	while(l<=r&&!is[i][r])r--;
	if(l>r)return;
	if(a[i][l]=='L')q.push({i,l});
	if(a[i][r]=='R')q.push({i,r});
}
void evaluoC(ll j){
	auto &l=lcol[j];
	auto &r=rcol[j];
	while(l<=r&&!is[l][j])l++;
	while(l<=r&&!is[r][j])r--;
	if(l>r)return;
	if(a[l][j]=='U')q.push({l,j});
	if(a[r][j]=='D')q.push({r,j});
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)fore(j,0,n)cin>>a[i][j];
		fore(i,0,n){
			lrow[i]=lcol[i]=0;
			rrow[i]=rcol[i]=n-1;
			fore(j,0,n)is[i][j]=1;
		}
		while(SZ(q))q.pop();
		fore(i,0,n)fore(j,0,n)evaluoR(i),evaluoC(i);
		ll cnt=0;
		while(SZ(q)){
			auto [i,j]=q.front(); q.pop();
			if(!is[i][j])continue;
			is[i][j]=0;
			evaluoR(i);
			evaluoC(j);
			cnt++;
			// cout<<"saco "<<i<<","<<j<<"\n";
		}
		// cout<<cnt<<" cnt\n";
		if(cnt!=n*n)cout<<"IM";
		cout<<"POSIBLE\n";
	}
	return 0;
}