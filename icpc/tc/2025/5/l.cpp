#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef pair<ii,ii> node;
const ll maxn=2e3+5;
vector<node> dir={(node){(ii){-1,0},{0,0}},(node){(ii){1,0},{0,0}},(node){(ii){0,1},{0,1}},(node){(ii){0,-1},{1,0}}};
ii dst[maxn][maxn];
ll vis[maxn][maxn];
ll n,m;
ii operator +(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
bool comp(ii a, ii b){
	if(a.fst!=b.fst){
		return a.fst<b.fst;
	}
	return a.snd<b.snd;
}
void bfs(ll i, ll j){
	deque <ii> dq;
	dq.pb({i,j});
	dst[i][j]={0,0};
	while(SZ(dq)){
		i=dq.front().fst;
		j=dq.front().snd;
		dq.pop_front();
		if(vis[i][j]>=2) continue;
		// cout<<i<<" "<<j<<"\n";
		// cout<<dst[i][j].fst<<" "<<dst[i][j].snd<<"\n";
		vis[i][j]=2;
		for(auto [ij,ps]: dir)if(i+ij.fst>=0 && i+ij.fst<n && j+ij.snd>=0 && j+ij.snd<m && vis[i+ij.fst][j+ij.snd]<2){
			auto D=dst[i][j]+ps;
			
			// cout<<i+ij.fst<<" "<<j+ij.snd<<"viendo\n";
			if(!ij.snd && comp(D,dst[i+ij.fst][j+ij.snd])) {
				// cout<<"agrego al frente\n";
				dst[i+ij.fst][j+ij.snd]=D;
				dq.push_front({i+ij.fst,j+ij.snd});
			}
			else if(!vis[i+ij.fst][j+ij.snd]){
				vis[i+ij.fst][j+ij.snd]=1;
				// cout<<"agrego atras\n";
				dst[i+ij.fst][j+ij.snd]=D;
				dq.pb({i+ij.fst,j+ij.snd});
			}
		}
	}
}
int main(){
	JET
	cin>>n>>m;
	ll r,c; cin>>r>>c;
	ll x,y; cin>>x>>y;
	fore(i,0,n)fore(j,0,m) dst[i][j]={1e9,1e9};
	fore(i,0,n)fore(j,0,m){
		char x; cin>>x; vis[i][j]=(x=='*')*3;
	}
	r--,c--;
	bfs(r,c);
	ll res=0;
	fore(i,0,n)fore(j,0,m){
		res+=(vis[i][j]==2 && dst[i][j].fst<=x && dst[i][j].snd<=y);
	}
	cout<<res<<"\n";
	return 0;
}
// 4 5
// 3 2
// 1 2
// .....
// .***.
// ...**
// *....
// 20
// edu@edu-IdeaPad-3-14ITL6:~/tc/5$ ./a
// 4 4
// 2 2
// 0 1
// ....
// ..*.
// ....
// ....
// 16
