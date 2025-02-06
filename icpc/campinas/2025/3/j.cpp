#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll vis[3000][3000];

int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	char a[n][m];
	fore(i,0,n)fore(j,0,m) cin>>a[i][j];
	ii r[k];
	fore(i,0,k) cin>>r[i].fst>>r[i].snd;
	vis[0][0]=1;
	queue<ii> q;
	q.push({0,0});
	ll rta=-1;
	
	while(!vis[n-1][m-1]){
		vector<ii> aux;
		rta++;
		while(q.size()){
			auto[x,y] = q.front();
			q.pop();
			aux.pb({x,y});
			if(x<n-1 && a[x+1][y]=='.' && !vis[x+1][y]){
				vis[x+1][y]=1;
				q.push({x+1,y});
			}
			if(y<m-1 && a[x][y+1]=='.' && !vis[x][y+1]){
				vis[x][y+1]=1;
				q.push({x,y+1});
			}
		}
		for(auto [x,y]:aux){
			// cout<<"debugg "<<x<<" "<<y<<" "<<SZ(q)<<endl;
			if(x>0 && !vis[x-1][y] &&a[x-1][y]=='.'){
				vis[x-1][y]=1;
				q.push({x-1,y});				
			}
			if(y>0 && !vis[x][y-1] &&a[x][y-1]=='.'){
				vis[x][y-1]=1;
				q.push({x,y-1});				
			}
		}
	}
	ll num=1e17,cnt=0;
	for(auto[x,y]:r){
		ll local=rta*(x+y)+x*(n+m-2);
		if(local==num) cnt++;
		if(local<num){
			num=local;
			cnt=1;
		}
	}
	cout<<num<<" "<<cnt<<"\n";
	
	
	
	return 0;
}