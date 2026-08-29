#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1005*1005*2 * 2;
vector<vv> g,gt; vv ord;
ll vis[MAXN], cmp[MAXN], truth[MAXN], qcmp = 0, N; //cmp[x]:scc of x.truth[x]:bool value for 2sat  
void dfsk(ll x, ll t){
	vis[x] = 1; if(t) cmp[x] = qcmp;
    for(auto y:t ? gt[x]:g[x])if(!vis[y]) dfsk(y,t);
    if(!t) ord.pb(x);
}
void scc(){
	qcmp=0; ord.clear(); memset(vis,0,sizeof(ll)*N);
    fore(i,0,N) if(!vis[i]) dfsk(i,0);
    reverse(ALL(ord)); memset(vis,0,sizeof(ll)*N);
    for(auto x:ord)if(!vis[x]) dfsk(x,1),qcmp++;
}
// 2SAT, first define N = 2 * vars
ll neg(ll x){return N-x-1;}
void add_or(ll x, ll y){
    g[neg(x)].pb(y); g[neg(y)].pb(x);
    gt[x].pb(neg(y)); gt[y].pb(neg(x));
}
bool satis(){
	scc();
    fore(i,0,N){
		if(cmp[i] == cmp[neg(i)]) return false;
        truth[i] = cmp[i] > cmp[neg(i)];
    }
    return true;
}
void add_eq(ll a, ll b){
	add_or(a,neg(b));
	add_or(neg(a),b);
}
void add_xor(ll a, ll b){
	add_or(a,b);
	add_or(neg(a),neg(b));
}
void add_truth(ll a, ll tv){
	if(tv)add_or(a,a);
	else add_or(neg(a),neg(a));
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		N=(n+1)*(m+1)*2 * 2;
		g.clear(); gt.clear();
		g.resize(N),gt.resize(N);
		auto cv=[&](ll i, ll j, ll sid){ // sid=0: ver, sid=1: hor
			return ((m+1)*i+j)*2+sid;
		};
		vector<string> ts(n,string(m,'.'));
		fore(i,0,n)fore(j,0,m){
			char t; cin>>t; ts[i][j]=t;
			ll a=cv(i,j,0);
			ll b=cv(i,j+1,1);
			ll c=cv(i+1,j,0);
			ll d=cv(i,j,1);
			vv vars={a,b,c,d};
			if(t=='0'||t=='9')for(auto i:vars)add_truth(i,t=='9');
			if(t=='1')add_eq(a,c),add_eq(b,d),add_xor(a,b);
			if(t=='2')add_xor(a,c),add_xor(b,d);
			if('3'<=t&&t<='8'){
				vv va;
				char cnt='3';
				fore(i,0,4)fore(j,i+1,4){
					if(cnt++==t){
						va={i,j};
						break;
					}
				}
				assert(SZ(va)==2);
				fore(i,0,4)if(!count(ALL(va),i))add_truth(vars[i],0);
				add_xor(vars[va[0]],vars[va[1]]);
			}
			if(t=='A')add_xor(a,c),add_truth(b,1),add_truth(d,1);
			if(t=='B')add_xor(b,d),add_truth(a,1),add_truth(c,1);
		}
		fore(i,0,n+1){
			add_truth(cv(i,0,1),0);
			add_truth(cv(i,m,1),0);
			add_truth(cv(i,m,0),0);
		}
		fore(j,0,m+1){
			add_truth(cv(0,j,0),0);
			add_truth(cv(n,j,0),0);
			add_truth(cv(n,j,1),0);
		}
		ll could=satis();
		assert(could);
		vector<string> a(2*n-1,string(2*m-1,'.'));
		fore(i,0,SZ(a))fore(j,0,SZ(a[0]))if(i%2==0&&j%2==0&&ts[i/2][j/2]!='0')a[i][j]='o';
		fore(i,0,n+1)fore(j,0,m+1){
			if(1){ // vertical
				ll x=cv(i,j,0);
				ll pi=2*i-1,pj=2*j;
				if(truth[x]){
					// cerr<<i<<","<<j<<" vertical: "<<x<<"\n";
					assert(pi>=0&&pi<SZ(a));
					assert(pj>=0&&pj<SZ(a[0]));
					a[pi][pj]='|';
				}
			}
			if(1){ // horizontal
				ll x=cv(i,j,1);
				ll pi=2*i,pj=2*j-1;
				if(truth[x]){
					assert(pi>=0&&pi<SZ(a));
					assert(pj>=0&&pj<SZ(a[0]));
					a[pi][pj]='-';
				}
			}
		}
		fore(i,0,SZ(a))cout<<a[i]<<"\n";
	}
	return 0;
}