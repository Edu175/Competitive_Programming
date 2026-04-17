#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=125;
// 0 pozo, 1 nada, 2 mounstro, 3 exit
vector<ll>dir;
ll n,m;
ll a[MAXN*MAXN],d[MAXN*MAXN][MAXN];
ii p[MAXN*MAXN][MAXN]; // nodo , flechas
bool allowed(ll x, ll w){
	if(w==0&&x/m==0)return 0;
	if(w==1&&x%m==0)return 0;
	if(w==2&&x%m==m-1)return 0;
	if(w==3&&x/m==n-1)return 0;
	if(!a[x+dir[w]])return 0;
	return 1;
}
ii res={-1,-1};
void bfs(ll s, ll k){
	queue<ii>q;
	q.push({s,k});
	d[s][k]=1;
	fore(i,0,MAXN*MAXN)fore(j,0,MAXN)p[i][j]={-1,-1};
	while(SZ(q)&&res.fst==-1){
		auto f=q.front(); q.pop();
		ll x=f.fst,c=f.snd;
		assert(x>=0&&x<n*m&&a[x]);
		fore(i,0,SZ(dir)){
			if(!allowed(x,i))continue;
			ll y=x+dir[i],ci=c-(a[y]==2);
			if(ci<0||d[y][ci])continue;
			d[y][ci]=1;
			p[y][ci]={x,c};
			q.push({y,ci});
			if(a[y]==3){
				res={y,ci};
				break;
			}
		}
	}
}
int main(){FIN;
	ifstream cin;   cin.open("tesoro.in", ios::in);
	ofstream cout; cout.open("tesoro.out", ios::out);
	ll f; cin>>n>>m>>f;
	dir={-m,-1,1,m};
	fore(i,0,n)fore(j,0,m){
		char c; cin>>c;
		ll x=m*i+j;
		if(c=='W')a[x]=2;
		else if(c=='V')a[x]=1;
		else if(c=='T')a[x]=3;
		else a[x]=0;
	}
	if(a[0]==2)f--;
	if(!a[0]||f<0){
		cout<<"imposible\n";
		return 0;
	}
	if(a[0]==3){
		cout<<"1\n(0,0)\n";
		return 0;
	}
	bfs(0,f);
	if(res.fst==-1){
		cout<<"imposible\n";
		return 0;
	}
	vector<ll>ans;
	for(ii x=res;x.fst!=-1;x=p[x.fst][x.snd])ans.pb(x.fst);
	reverse(ALL(ans));
	cout<<SZ(ans)<<"\n";
	for(auto i:ans)cout<<"("<<i/m<<","<<i%m<<")\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
