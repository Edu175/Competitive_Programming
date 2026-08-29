#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=405,MAXV=25;

ll d[MAXN][MAXN][MAXV][4];

ll n,m;
ll sp[MAXN][MAXN];

ll get(ll i0, ll i1, ll j0, ll j1){ // [i0,i1) x [j0,j1)
	return sp[i1][j1]-sp[i1][j0]-sp[i0][j1]+sp[i0][j0];
}

bool allowed(ii a, ii b){ // a -> b
	if(b.fst<0||b.fst>=n||b.snd<0||b.snd>=m)return 0;
	if(a>b)swap(a,b);
	ll cant= get(a.fst,b.fst+1,a.snd,b.snd+1);
	return cant==0;
}
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii operator*(ii a, ll t){return {a.fst*t,a.snd*t};}
vector<ii> dirs={{1,0},{0,1},{-1,0},{0,-1}};

// ll fn(ll n){}

ll bfs(){
	if(n==1&&m==1)return 0;
	mset(d,-1);
	queue<array<ll,4>> q;
	q.push({0,0,0,0}); d[0][0][0][0]=0;
	while(SZ(q)){
		// ll did=0;
		fore(wh,0,3)fore(nt,0,(wh==2?4:1)){
			auto [i,j,v,t]=q.front();
			// if(!did)cerr<<i<<","<<j<<" "<<v<<" "<<t<<"\n";
			if(wh==2&&t==nt)continue;
			if(v&&wh==2)continue;
			
			ll cur=d[i][j][v][t];
			
			if(!wh)v++;
			if(wh==1)v--;
			if(wh==2)t=nt;
			// avanza
			if(v<0||v>=MAXV)continue;
			ii me={i,j};
			ii he=me+dirs[t]*v;
			if(!allowed(me,he))continue;
			tie(i,j)=he;
			
			
			
			if(d[i][j][v][t]==-1){
				d[i][j][v][t]=cur+1;
				if(i==n-1&&j==m-1)return cur+1;
				q.push({i,j,v,t});
			}
		}
		q.pop();
	}
	return -1;
}

int main(){FIN;
	cin>>n>>m;
	vector<vv> a(n,vv(m));
	fore(i,0,n)fore(j,0,m){
		char c; cin>>c;
		a[i][j]=c-'0';
	}
	if(a[0][0]||a[n-1][m-1]){
		cout<<"-1\n";
		return 0;
	}
	fore(i,1,n+1)fore(j,1,m+1)sp[i][j]=sp[i][j-1]+a[i-1][j-1];
	fore(i,1,n+1)fore(j,1,m+1)sp[i][j]+=sp[i-1][j];
	ll res=bfs();
	cout<<res<<"\n";
	return 0;
}
