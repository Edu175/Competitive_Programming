#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=205;

ll n,m;
ll a[MAXN],vis[MAXN];
ll dp[MAXN][MAXN][MAXN];
ll f(ll i, ll c, ll s){
	ll &res=dp[i][c][s];
	if(res!=-1)return res;
	if(i==n)return res=(c==m&&s==0);
	if(c>m)return res=0;
	res=f(i+1,c,s);
	if(!vis[i])res=max(res,f(i+1,c+1,(s+a[i])%m));
	return res;
}
vector<ll>ans;
void build(ll i, ll c, ll s){
	ll &res=dp[i][c][s];
	if(i==n)return;
	if(!vis[i]&&res==f(i+1,c+1,(s+a[i])%m))ans.pb(i),build(i+1,c+1,(s+a[i])%m);
	else build(i+1,c,s);
}
int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	vector<pair<ll,ll>>s(k);
	fore(i,0,k)cin>>s[i].fst,s[i].snd=i;
	sort(ALL(s));
	vector<vector<ll>>res(k);
	ll flag=1;
	fore(i,0,k-1){
		m=s[i].fst;
		fore(j,0,n+3)fore(k,0,m+3)fore(l,0,m+3)dp[j][k][l]=-1;
		ans.clear();
		if(!f(0,0,0)){
			flag=0;
			break;
		}
		build(0,0,0);
		res[s[i].snd]=ans;
		for(auto i:ans)vis[i]=1;
	}
	if(!flag){ //no va a pasar
		cout<<"-1\n";
		return 0;
	}
	ans.clear();
	m=s[k-1].fst;
	ll d=0;
	fore(i,0,n)if(!vis[i]){
		ans.pb(i);
		d=(d+a[i])%m;
	}
	d=m-d;
	res[s[k-1].snd]=ans;
	cout<<d<<"\n";
	fore(i,0,k){
		for(auto j:res[i])cout<<a[j]<<" ";
		if(i==s[k-1].snd)cout<<d;
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
