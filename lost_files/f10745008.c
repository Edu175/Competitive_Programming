#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=9000005;

vector<ll> g[MAXN];
ll block[MAXN];

void dfs(ll x){
	ll cnt=0;
	for(auto i:g[x]){
		if(!block[i])cnt++;
	}
	if(cnt<2){
		block[x]=1;
		for(auto i:g[x]){
			if(!block[i])dfs(i);
		}
	}
}

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("input.txt", ios::in);
	cout.open("output.txt", ios::out);
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n,m; cin>>n>>m;
		char a[n][m];
		set<ll>rock;
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
				if(a[i][j]=='#')rock.insert(m*i+j);
			}
		}
		fore(i,0,n){
			fore(j,0,m){
				if(i&&a[i-1][j]!='#')g[m*i+j].pb(m*(i-1)+j);
				if(i<n-1&&a[i+1][j]!='#')g[m*i+j].pb(m*(i+1)+j);
				if(j&&a[i][j-1]!='#')g[m*i+j].pb(m*i+j-1);
				if(j<m-1&&a[i][j+1]!='#')g[m*i+j].pb(m*i+j+1);
			}
		}
		for(auto i:rock){
			for(auto j:g[i]){
				if(!block[j])dfs(j);
			}
		}
		if(!block[0])dfs(0);
		if(!block[m-1])dfs(m-1);
		if(!block[m*(n-1)])dfs(m*(n-1));
		if(!block[m*n-1])dfs(m*n-1);
		char res[n][m];
		ll flag=1;
		fore(i,0,n){
			fore(j,0,m){
				if(a[i][j]=='#')res[i][j]='#';
				else if(!block[m*i+j])res[i][j]='^';
				else if(a[i][j]!='^')res[i][j]='.';
				else{
					flag=0;
					break;
				}
			}
			if(!flag)break;
		}
		if(flag){
			cout<<"Possible\n";
			fore(i,0,n){
				fore(j,0,m){
					cout<<res[i][j];
				}
				cout<<"\n";
			}
		}
		else cout<<"Impossible\n";
		fore(i,0,n*m)g[i].clear(), block[i]=0;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
