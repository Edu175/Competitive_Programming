#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef unsigned long long ull;

int k,n,m; 
const int maxn = 3001;
ll g[maxn][maxn];
ll snake[maxn][maxn];
ll timer[maxn][maxn];


vector<ii> dir = {{1,0},{-1,0},{0,1},{0,-1}};

bool valid(int x, int y){
	if(x<0 || x>=n) return false;
	if(y<0 || y>=m)  return false;
	return g[x][y];
}

int main(){
	JET
	cin>>n>>m>>k;
	mset(snake,-1);
	ii st;
	fore(i,0,k){
		ll x,y; cin>>x>>y;
		x--,y--;
		snake[x][y] = i;
		if(!i) st = {x,y};
		// cout<<x<<" "<<y<<endl;
	}
	fore(i,0,n)fore(j,0,m){
		char c; cin>>c;
		if(c == '.')g[i][j] = 1;
		// cout<<"asdnioasndoasd"<<" "<<i<<" "<<j<<endl;
	}
	mset(timer,-1);
	timer[st.fst][st.snd] = 0;
	priority_queue<pair<ll,ii>> pq;
	pq.push({0,st});
	ull rta = 0;
	while(SZ(pq)){
		auto [t,pos] = pq.top(); pq.pop();
		t=-t;
		auto [x,y] = pos;
		// cout<<t<<" "<<x<<" "<<y<<endl;
		if(t != timer[x][y]) continue;
		rta += ((ull)t*(ull)t);
		for(auto d:dir){
			ll nx = x + d.fst, ny = y + d.snd, nt = t+1;
			if(!valid(nx,ny)) continue;
			if(snake[nx][ny] >= 0){
				ll i = snake[nx][ny];
				if(i+nt < k) nt += k - (i+nt);
				// if(nx == 2 && ny == 3) cout<<nt<<" "<<x<<" "<<y<<" "<<i<<"\n";
			}
			if(timer[nx][ny] == -1 || nt < timer[nx][ny]){
				timer[nx][ny] = nt;
				pq.push({-nt,{nx,ny}});
			}
		}
	}
	// fore(i,0,n){
		// fore(j,0,m) cout<<timer[i][j]<<" ";
		// cout<<"\n";
	// }
	cout<<rta<<"\n";
	return 0;
}