#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int MAXN=1e3;
pair<ii,vector <pair<int, char>>> uf[MAXN];
void init(){fore(i,0,MAXN) uf[MAXN].fst={-1,-1};}
int find(int x) {
	if(uf[x].fst.fst<0) return x;
	uf[x].fst.fst=find(uf[x].fst.fst);
}
bool join(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return false;
	if(uf[x].fst.fst>uf[y].fst.fst)swap(x,y);
	fore(i,0,SZ(uf[y].snd)) uf[x].snd.pb(uf[y].snd[i]);
	uf[x].fst.fst+=uf[y].fst.fst;uf[y].fst.fst=x;
	uf[x].fst.snd=max(uf[x].fst.snd,uf[y].fst.snd);
	return true;
}
void upd(int x, int y, char c){
	x=find(x);
	int j=(c=='>');
	uf[x].pb({y,j});
}
int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m; cin>>n>>m;
	char a[n]; fore(i,0,n) a[i]='?';
	fore(i,0,m){
		string s; cin>>s;
		int a,b;
		fore(i,0,SZ(s)){
			
		}
		
	}
	
	
}