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
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=55;

vector<ll>dir={1,-7,-1,7};
ll go(ll x, ll w){
	if(w==0&&x%7==6)return 52;
	if(w==1&&x/7==0)return 52;
	if(w==2&&x%7==0)return 52;
	if(w==3&&x/7==6)return 52;
	return x+dir[w];
}
ll mov[MAXN];
ll deg[MAXN],vis[MAXN];
ll dfs(ll x, ll i){
	//cout<<x<<" "<<i<<"\n";
	if(vis[x])return 0;
	if(x==42)return i==48;
	vis[x]=1;
	ll g=-1,c=0;
	fore(w,0,4){
		auto y=go(x,w);
		deg[y]--;
		if(!vis[y]&&y!=42&&deg[y]<=1)g=w,c++;
	}
	ll res=0;
	if(!(c>1)&&!(mov[i]!=-1&&g!=-1&&mov[i]!=g)){
		if(mov[i]!=-1)g=mov[i];
		if(g!=-1)res=dfs(go(x,g),i+1);
		else {
			fore(w,0,4)res+=dfs(go(x,w),i+1);
		}
	}
	fore(w,0,4){
		auto y=go(x,w);
		deg[y]++;
	}
	vis[x]=0;
	return res;
}
int main(){FIN;
	string s; cin>>s;
	map<char,ll>mp;
	mp['R']=0;
	mp['U']=1;
	mp['L']=2;
	mp['D']=3;
	mp['?']=-1;
	fore(i,0,SZ(s))mov[i]=mp[s[i]];
	fore(i,0,7)fore(j,0,7){
		ll x=7*i+j;
		deg[x]=4;
		if(i==0)deg[x]--;
		if(i==6)deg[x]--;
		if(j==0)deg[x]--;
		if(j==6)deg[x]--;
	}
	/*fore(i,0,7){
		fore(j,0,7)cout<<deg[7*i+j];
		cout<<"\n";
	}*/
	vis[52]=deg[52]=1000;
	cout<<dfs(0,0)<<"\n";
	return 0;
}
