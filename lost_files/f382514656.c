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
bool ord_vis[MAXN];
vector<ll>g[MAXN];
vector<ll>ord;
pair<ll,ll> operator+(pair<ll,ll>p1,pair<ll,ll>p2){
	return {p1.fst+p2.fst,p1.snd+p2.snd};
}
void dfs(ll x){
	for(auto i:g[x]){
		if(!vis[i])dfs(i);
	}
	ord_vis[x]=1;
	ord.pb(x);
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
    fore(i,0,n)pag[i]--;
//===================================PARSEO=========================================
	fore(i,0,n)if(!ord_vis[i])dfs(i);
	reverse(ALL(ord));
	mset(vis,-1);
    fore(i,0,n){
    	pair<ll,ll> res=dfs(i,i);
    	celdasTotal.pb(res.fst);
    	celdasMismaHoja.pb(res.snd);
    }
}
