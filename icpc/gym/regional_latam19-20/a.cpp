#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
const ll MAXNm=1024;
vector<int> g[MAXNm]; // [0,n)->[0,m)
int n,m;
int mt[MAXNm],mt2[MAXNm],ds[MAXNm];
bool bfs(){
	queue<int> q;
	memset(ds,-1,sizeof(ds));
	fore(i,0,n)if(mt2[i]<0)ds[i]=0,q.push(i);
	bool r=false;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:g[x]){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
			else if(mt[y]<0)r=true;
		}
	}
	return r;
}
bool dfs(int x){
	for(int y:g[x])if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y])){
		mt[y]=x;mt2[x]=y;
		return true;
	}
	ds[x]=1<<30;
	return false;
}
int mm(){
	int r=0;
	memset(mt,-1,sizeof(mt));memset(mt2,-1,sizeof(mt2));
	while(bfs()){
		fore(i,0,n)if(mt2[i]<0)r+=dfs(i);
	}
	return r;
}
const ll MAXN=105,MAXB=1005,MAXMK=1024;

set<ll> a[MAXN];

set<ll> operator&(set<ll>a, set<ll>b){
	set<ll>r;
	for(auto i:a)if(b.count(i))r.insert(i);
	return r;
}

int main(){ET
	map<string,ll>mp;
	ll n; cin>>n;
	ll cnt=0;
	fore(i,0,n){
		ll m; cin>>m;
		fore(j,0,m){
			string s; cin>>s;
			if(!mp.count(s))mp[s]=cnt++;
			a[i].insert(mp[s]);
		}
	}
	vv bad(n);
	fore(i,0,n)fore(j,0,n)if(i!=j){
		if(a[i]==a[j])bad[j]=i<j;
		else if((a[i]&a[j])==a[j])bad[j]=1;
	}
	vector<set<ll>>b;
	fore(i,0,n)if(!bad[i])b.pb(a[i]);
	n=SZ(b);
	fore(i,0,n)a[i]=b[i];
	
}