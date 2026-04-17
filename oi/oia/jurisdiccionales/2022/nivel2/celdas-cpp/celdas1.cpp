#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin,x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" "; cout<<"\n"
using namespace std;
typedef int ll;
const ll MAXN=1e4+3;
ll pag[MAXN],vis[MAXN];
vector<ll>g[MAXN];
ll dfs_tot(ll x, ll s){
	ll ret=0;
	vis[x]=s;
	for(auto i:g[x]){
		if(vis[i]!=s){
			ret++;
			ret+=dfs_tot(i,s);
		}
	}
	return ret;
}
ll dfs_mis(ll x,ll s){
	ll ret=0;
	vis[x]=s;
	for(auto i:g[x]){
		if(vis[i]!=s){
			ret+=(pag[i]==pag[s]);
			ret+=dfs_mis(i,s);
		}
	}
	return ret;
}

void celdas(vector <string> &c, vector <int> &celdasTotal, vector <int> &celdasMismaHoja) {
	ll n=SZ(c);
	vector<pair<string,ll>>edges;
	map<string,ll>pags,id;
    fore(i,0,n){
    	string a,pg, s=c[i];
    	ll r=0;
    	bool e=0;
    	fore(j,0,SZ(s)){
    		if(e){
    			if(s[j]=='='){
					r=j+1;
					break;
				}
				pg.pb(s[j]);
    		}
    		if(s[j]=='!')e=1;
    		a+=s[j];
    	}
    	id[a]=i;
    	if(!pags[pg])pags[pg]=SZ(pags)+1;
    	pag[i]=pags[pg];
    	s.pb('+');
    	string t;
    	fore(k,r,SZ(s)){
    		if(s[k]=='*'||s[k]=='+'||s[k]=='-'){
    			if(t[0]<'0'||t[0]>'9'){
    				edges.pb({t,i});
    			}
				t.clear();
			}
			else t+=s[k];
    	}
    }
    for(auto i:edges)g[id[i.fst]].pb(i.snd);
//===================================PARSEO=========================================
	mset(vis,-1);
    fore(i,0,n)celdasTotal.pb(dfs_tot(i,i));
    mset(vis,-1);
    fore(i,0,n)celdasMismaHoja.pb(dfs_mis(i,i));
}
