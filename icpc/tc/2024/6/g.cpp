#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

typedef ll tf;
typedef ll tc;
const tf INFFLOW=1e9;
const tc INFCOST=1e9;
struct MCF{
	int n;
	vector<tc> prio,pot;vector<tf> curflow; vector<int> prevedge, prevnode;
	priority_queue<pair<tc,int>,vector<pair<tc,int>>,greater<pair<tc,int>>> q;
	struct edge{int to,rev;tf f,cap; tc cost;};
	vector<vector<edge>> g;
	MCF(int n): n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	void add_edge(int s,int t,tf cap,tc cost){
		g[s].pb((edge){t,SZ(g[t]),0,cap,cost});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,-cost});
	}
	pair<tf,tc> get_flow(int s,int t){
		tf flow=0; tc flowcost=0;
		while(1){
			q.push({0,s});
			fill(ALL(prio),INFCOST);
			prio[s]=0; curflow[s]=INFFLOW;
			while(!q.empty()){
				auto cur=q.top();
				tc d=cur.fst;
				int u=cur.snd;
				q.pop();
				if(d!=prio[u]) continue;
				for(int i=0;i<SZ(g[u]);++i){
					edge &e=g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					tc nprio=prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio){
						prio[v]=nprio;
						q.push({nprio,v});
						prevnode[v]=u;prevedge[v]=i;
						curflow[v]=min(curflow[u],e.cap-e.f);
					}
				}
			}
			if(prio[t]==INFCOST) break;
			fore(i,0,n) pot[i]+=prio[i];
			tf df=min(curflow[t],INFFLOW-flow);
			flow+=df;
			for(int v=t;v!=s;v=prevnode[v]){
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+=df;g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return {flow,flowcost};
	}
	
};


// 0 -> empiezo , 1...n palabras, n+1..n+26 letras, n+27 salida
int main(){
	JET
	string s; cin>>s;
	int n; cin>>n;
	vv ocur(26,0);
	fore(i,0,SZ(s))ocur[s[i]-'a']++;
	MCF fl(n+28);
	fore(i,0,26){
		fl.add_edge(n+1+i,n+27,ocur[i],0);
	}
	fore(i,0,n){
		vv oc(26,0);
		string s1; cin>>s1; int x; cin>>x;
		fore(j,0,SZ(s1))oc[s1[j]-'a']++;
		fore(j,0,26){
			fl.add_edge(i+1,n+1+j,oc[j],0);
		}
		fl.add_edge(0,i+1,x,i+1);
	}
	auto [b,c]=fl.get_flow(0,n+27);
	if(b<SZ(s)){
		cout<<-1<<"\n";
	}
	else{
		cout<<c<<"\n";
	}
	return 0;
}