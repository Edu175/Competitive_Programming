#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int MAXN=2e5,C=50;
int main(){
	JET
	int n,m; cin>>n>>m;
	
	vector<vector <bool>> G(min(n,C),vector <bool> (min(n,C),false));
	fore(i,0,m){
		int a,b; cin>>a>>b; a--;b--;
		if(a>=C||b>=C)continue;
		G[a][b]=true;
		G[b][a]=true;		
	}
	vector<ll>p;
	fore(i,0,n)p.pb(i);
	// random_device rd;
	// mt19937 rng(rd());
	// shuffle(ALL(p),rng);
	fore(i,0,min(n,C))fore(j,0,i)fore(k,0,j)fore(r,0,k)fore(s,0,r){
		vector<ll>v={p[i],p[j],p[k],p[r],p[s]};
		ll mk=0;
		fore(edu,0,SZ(v)){
			fore(tito,edu+1,SZ(v)){
				mk|=1<<G[v[edu]][v[tito]];
			}
		}
		if(mk!=3){
			cout<<p[i]+1<<" "<<p[j]+1<<" "<<p[k]+1<<" "<<p[r]+1<<" "<<p[s]+1<<"\n"; return 0;
		}
		// if((G[i][j] && G[i][k] && G[i][r] && G[i][s] && G[j][k] && G[j][r] && G[j][s] && G[k][r] && G[k][s] && G[r][s]) || (!G[i][j] && !G[i][k] && !G[i][r] && !G[i][s] && !G[j][k] && !G[j][r] && !G[j][s] && !G[k][r] && !G[k][s] && !G[r][s])) {cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<r+1<<" "<<s+1<<"\n"; return 0;}
	}
	cout<<"-1\n"; return 0;
	
}