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
const ll MAXP=10000;
typedef bitset<MAXP> Mask;
ll n,m;
/*string bin(Mask mk){
	string s;
	fore(i,0,n){
		fore(j,0,m)s.pb('0'+mk[m*i+j]);
		s.pb('\n');
	}
	return s;
}*/

unordered_map<Mask,bool>dp;
vector<Mask> mv[MAXP];
Mask allones(0);
ll f(Mask mk){
	if(dp.count(mk))return dp[mk];
	bool &res=dp[mk];
	if(mk==allones){
		//cout<<bin(mk)<<"1\n\n";
		return res=1;
	}
	ll x=(~mk)._Find_first();
	for(auto m:mv[x])if((m&mk)==0&&f(mk|m))return res=1;
	//cout<<bin(mk)<<x<<":\n";
	//for(auto m:mv[x])if((m&mk)==0)cout<<bin(mk|m)<<"\n";
	//cout<<res<<"\n\n";
	return res=0;
}
vector<vector<ll>>a;
ll cnt=1;
void add(Mask mk){
	fore(i,0,n)fore(j,0,m)if(mk[m*i+j])a[i][j]=cnt;
	cnt++;
}
void build(Mask mk){
	if(mk==allones)return;
	ll x=(~mk)._Find_first();
	for(auto m:mv[x])if((m&mk)==0&&f(mk|m)){
		add(m);
		build(mk|m);
		return;
	}
}

//
const ll MAXN=105;
vector<ii>dir={{0,1},{-1,0},{0,-1},{1,0}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
bool allowed(ii x){
	if(x.fst<0||x.fst>=n||x.snd<0||x.snd>=m)return 0;
	return 1;
}
set<char>st;
ll vis[MAXN][MAXN];
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
		if(n==1||m==1||!(n%3==0||m%3==0)||(n==3&&(m&1))||(m==3&&(n&1))){
			cout<<"NO\n";
			continue;
		}
		allones=0;
		fore(i,0,n*m)allones[i]=1;
		dp.clear();
		ll qu[4]={0,1,m,m+1};
		Mask Ls[4]={};
		fore(i,0,4)fore(j,0,4)if(i!=j)Ls[i][qu[j]]=1;
		vector<Mask>all;
		fore(i,0,n-1)fore(j,0,m-1)fore(k,0,4)all.pb(Ls[k]<<(m*i+j));
		fore(i,0,n*m)mv[i].clear();
		for(auto mk:all){
			fore(i,0,n*m)if(mk[i])mv[i].pb(mk);
		}
		
		if(f(0)){
			cout<<"YES\n";
			a.clear();
			cnt=1;
			a.resize(n,vector<ll>(m));
			build(0);
			cv();
			fore(i,0,n){
				fore(j,0,m)cout<<b[i][j];
				cout<<"\n";
			}
		}
		else cout<<"NO\n";
	}
	return 0;
}
