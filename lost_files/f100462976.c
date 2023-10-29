#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin,x.end
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
const ll MAXN=1e4+5;
struct tri{
	ll let,num,pag;
};
map<tri,vector<tri>> g;
set<tri>vis;
vector<tri> nodos;
pair<ll,ll> operator+(pair<ll,ll>p1,pair<ll,ll>p2){
	return {p1.fst+p2.fst,p1.snd+p2.snd};
}
bool operator<(tri t1,tri t2){
	vector<ll> v1={t1.let,t1.num,t1.pag},v2={t2.let,t2.num,t2.pag};
	return v1<v2;
}
pair<ll,ll> dfs(tri x,ll pg){
	pair<ll,ll>ret;
	for(auto i:g[x]){
		if(!vis.count(i)){
			vis.insert(i);
			if(i.pag==pg)ret.snd++;
			ret.fst++;
			ret=ret+dfs(i,pg);
		}
	}
	return ret;
}

void celdas(vector <string> &c, vector <int> &celdasTotal, vector <int> &celdasMismaHoja) {
    map<string,ll>mp;
    for(auto s:c){
    	char let=s[0];
    	ll num=s[1];
    	string pag;
    	ll r=0;
    	fore(j,3,SZ(s)){
    		if(s[j]=='='){
    			r=j+1;
    			break;
    		}
    		pag.pb(s[j]);
    	}
    	if(mp[pag]==0)mp[pag]=SZ(mp)+1;
    	tri a={let-'A',num,mp[pag]};
    	nodos.pb(a);
    	while(s[r]<'0'||s[r]>'9'){
    		char let2=s[0];
			ll num2=s[1];
			string pag2;
			fore(j,3,SZ(s)){
				if(s[j]=='*'||s[j]=='+'||s[j]=='-'){
					r=j+1;
					break;
				}
				pag2.pb(s[j]);
			}
			if(mp[pag2]==0)mp[pag2]=SZ(mp)+1;
			tri b={let2-'A',num2,mp[pag2]};
			g[b].pb(a);
    	}
    }
    fore(i,0,SZ(c)){
    	tri nod=nodos[i];
    	pair<ll,ll> res=dfs(nod,nod.pag);
    	vis.clear();
    	celdasTotal[i]=res.fst;
    	celdasMismaHoja[i]=res.snd;
    }
    
}
/*int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> c;
    c.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> c[i0];
    }
    vector<int> celdasTotal;
    celdasTotal.resize(0);
    vector<int> celdasMismaHoja;
    celdasMismaHoja.resize(0);
    celdas(c, celdasTotal, celdasMismaHoja);
    for (int i = 0; i < int(celdasTotal.size()); i++) {
        if (i > 0) cout << " ";
        cout << celdasTotal[i];
    }
    cout << "\n";
    for (int i = 0; i < int(celdasMismaHoja.size()); i++) {
        if (i > 0) cout << " ";
        cout << celdasMismaHoja[i];
    }
    cout << "\n";
    return 0;
}*/
