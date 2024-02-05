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
typedef vector<vector<ll>> grid;
grid rot(grid a){
	ll n=SZ(a),m=SZ(a[0]);
	grid ai(m,vector<ll>(n));
	fore(i,0,n)fore(j,0,m)ai[m-1-j][i]=a[i][j];
	return ai;
}
ll cnt=1;
void paste(grid &a, grid b, ll x, ll y){
	assert(x+SZ(b)<=SZ(a)&&y+SZ(b[0])<=SZ(a[0]));
	fore(i,0,SZ(b))fore(j,0,SZ(b[0]))a[x+i][y+j]=b[i][j];
}
grid f(ll n, ll m){
	if((!(n%3==0)&&!(m%3==0))||n==1)return {{-1}};
	if(!(m%3==0))return rot(f(m,n));
	if((n&1)&&m==3)return {{-1}}; //
	if(n%3==0&&m%3==0&&n==3&&m!=3)return rot(f(m,n));
	grid a(n,vector<ll>(m));
	if(n==2&&m==3){
		a={
			{cnt,cnt  ,cnt+1},
			{cnt,cnt+1,cnt+1}
		};
		cnt+=2;
		return a;
	}
	if(n==5&&m==9){
		a={
			{1,2,2,3,3,4,4,5,5},
			{1,1,2,6,3,7,4,8,5},
			{9,9,6,6,7,7,10,8,8}, 
			{11,9,12,13,13,14,10,10,15}, 
			{11,11,12,12,13,14,14,15,15}
		};
		fore(i,0,n)fore(j,0,m)a[i][j]+=cnt-1;
		cnt+=15;
		return a;
	}
	if(n==5&&m==6){
		fore(i,0,3)paste(a,f(3,2),0,2*i);
		fore(i,0,2)paste(a,f(2,3),3,3*i);
		return a;
	}
	if(n&1){
		assert(n>=5);
		ll s=0;
		if(m&1)paste(a,f(5,9),0,0),s=9;
		for(ll i=s;i<m;i+=6)paste(a,f(5,6),0,i);
		if(n-5)paste(a,f(n-5,m),5,0);
		return a;
	}
	fore(i,0,n/2)fore(j,0,m/3)paste(a,f(2,3),i*2,j*3);
	return a;
}

const ll MAXN=105;
vector<ii>dir={{0,1},{-1,0},{0,-1},{1,0}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll n,m;
bool allowed(ii x){
	if(x.fst<0||x.fst>=n||x.snd<0||x.snd>=m)return 0;
	return 1;
}
set<char>st;
ll vis[MAXN][MAXN];
grid a;
char b[MAXN][MAXN];
vector<ii>c;
void dfs(ii x){
	vis[x.fst][x.snd]=1;
	c.pb(x);
	fore(d,0,4){
		ii y=x+dir[d];
		if(!allowed(y))continue;
		if(a[y.fst][y.snd]==a[x.fst][x.snd]){
			if(!vis[y.fst][y.snd])dfs(y);
		}
		else if(vis[y.fst][y.snd])st.erase(b[y.fst][y.snd]);
	}
}
void cv(){
	mset(vis,0);
	set<char>col;
	fore(i,0,26)col.insert('A'+i);
	fore(i,0,n)fore(j,0,m)if(!vis[i][j]){
		st=col;
		c.clear();
		dfs({i,j});
		char u=*st.begin();
		for(auto [x,y]:c)b[x][y]=u;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		cnt=1;
		//cout<<n<<" "<<m<<endl;
		a=f(n,m);
		//cout<<n<<","<<m<<": ";
		if(a[0][0]==-1)cout<<"NO\n";
		else {
			cout<<"YES\n";
			//cout<<endl;
			cv();
			fore(i,0,n){
				fore(j,0,m)cout<<b[i][j];
				cout<<"\n";
			}
		}
	}
	return 0;
}
