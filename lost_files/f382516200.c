#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=4e6+5;


vector<ll>g[MAXN];
vector<ll>q,qi;
ll a[MAXN];
bool vis[MAXN];
ll n;
vector<ll>dir={-n,-1,1,n};
bool allow(ll x, ll d){
	if(x+d<0||x+d>=n*n)return 0;
	if(x%n==0&&d==-1)return 0;
	if(x%n==n-1&&d==1)return 0;
	return 1;
}
void dfs(ll x){
	//cout<<x<<"\n";
	for(auto i:dir){
		//cout<<x+i<<": "<<allow(x,i)<<" "<<vis[x+i]<<" | "<<a[x+i]<<"\n";
		if(allow(x,i)&&!vis[x+i]){
			vis[x+i]=1;
			if(a[x]==a[x+i])dfs(x+i);
			else qi.pb(x+i);
		}
	}
}

int main(){
	ifstream cin;
	ofstream cout;
	cin.open("uniformar.in", ios::in);
	cout.open("uniformar.out", ios::out);
	cin>>n;
	dir={-n,-1,1,n};
	fore(i,0,n){
		string s; cin>>s;
		fore(j,0,n)a[n*i+j]=s[j]-'0';
	}
	q.pb(0);
	ll res=0;
	while(SZ(q)){
		for(auto i:q)dfs(i);
		q=qi;qi.clear();
		//imp(q);
		//cout<<"==========================================\n";
		res++;
	}
	cout<<res-1<<"\n";
	return 0;
}
