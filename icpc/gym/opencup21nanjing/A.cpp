#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll n=10,m=10;
ll a[20][20];
ll vis[20][20];
vector<ii> dir={ii({1,0}),ii({0,1}),ii({-1,0}),ii({0,-1})};
ll e;
ii operator+(ii a, ii b){return ii({a.fst+b.fst,a.snd+b.snd});}
bool check(ii v){
	return (v.fst>=0&&v.fst<n)&&(v.snd>=0&&v.snd<m)&&(vis[v.fst][v.snd]<2);
}
void dfs(ii v){
	vis[v.fst][v.snd]++;
	a[v.fst][v.snd]=1;
	ll b=e;
	while(e!=b+4){
		if(check(dir[e%4]+v)){
			fore(i,0,4)fore(j,0,4){
				if((i!=j&&i!=e%4&&check(dir[j]+dir[i]+v))){
					auto [p,q]=dir[i]+dir[j]+v;
					vis[p][q]++;
				}
				else if(check(dir[i]+v)){
					auto [p,q]=dir[i]+v;
					vis[p][q]++;
				}
			}
			dfs(dir[e%4]+v);
			break;
		}
		else e++;
	}
	return;
}
int main(){
	JET
	cin>>n>>m;
	ll x,y; cin>>x>>y;
	fore(i,0,4)if((ii){x,y}==dir[i]) e=i;
	cin>>x>>y;
	cout<<n<<" "<<n<<"\n";
	dfs((ii){x,y});
	fore(i,0,n){
		fore(j,0,m) cout<<a[i][j];
		cout<<"\n";
	}
	return 0;
}