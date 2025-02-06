#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=(1<<11);
vector<int> g[MAXN];
int n,m;
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(){
	queue<int> q;
	mset(ds,-1);
	fore(i,0,n)if(mt2[i]<0)ds[i]=0,q.push(i);
	bool r=false;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:g[x]){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
			else if(mt[y]<0) r=true;
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
	mset(mt,-1);mset(mt2,-1);
	while(bfs()){
		fore(i,0,n)if(mt2[i]<0)r+=dfs(i);
	}
	return r;
}
bitset<MAXN> vis,mal,cer;
vv G[MAXN];
ll pos[MAXN], invn[MAXN],invm[MAXN];
void dfsb(ll i, bool b){
	auto mat=(b?mt:mt2);
	auto inv=(b?invn:invm);
	vis[i]=1;
	mal[i]=1;
	for(ll j:G[i])if(!vis[inv[mat[pos[j]]]]){
		dfsb(inv[mat[pos[j]]],b);
	}
}
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll nn,c; cin>>nn>>c;
		ll p=0;
		n=0;
		m=0;
		string s1,s2; cin>>s1>>s2;
		fore(i,0,nn)p|=((s1[i]==s2[i]?1ll:0ll)<<i);
		set<ll> nou;
		fore(i,0,c){
			string w; cin>>w;
			ll apa=0;
			//cout<<w<<"\n";
			fore(j,0,nn){
				//cout<<((w[j]=='='?1ll:0ll)<<j)<<"\n";
				apa|=((w[j]=='='?1ll:0ll)<<j);
			}
			nou.insert(apa);
		}
	//	for(auto l:nou) cout<<l<<" ";;cout<<"\n";
		ll mk=0;mset(pos,-1);
		while(mk<((1<<nn))){
			if(nou.count(mk)){
				mk++;
				continue;
			}
			if(ll(__builtin_popcountll(mk))&1ll) {
				pos[mk]=n;
				invn[n]=mk;
				n++;
			}
			else {
				pos[mk]=m;
				invm[m]=mk;
				m++;
			}
			mk++;
		}
		mk=0;
		while(mk<((1<<nn))){
			if(nou.count(mk)){
				mk++;
				continue;
			}
				fore(i,0,nn){
					ll vec=mk^(1<<i);
					if(nou.count(vec)) continue;
					G[mk].pb(vec);
					if(ll(__builtin_popcountll(mk))&1ll) {
						g[pos[mk]].pb(pos[vec]);
					}
				}

			mk++;
		}
		mm();
		fore(i,0,n)if(mt2[i]<0){vis&=cer;dfsb(invn[i],1);}
		fore(i,0,m)if(mt[i]<0){vis&=cer;dfsb(invm[i],0);}
		/*fore(i,0,n){cout<<"a "<<i<<" le corresponde "<<invn[i]<<" match con"<<mt2[i]<<endl;}
		
		fore(i,0,m){cout<<"(m)a "<<i<<" le corresponde "<<invm[i]<<" match con"<<mt[i]<<endl;}*/
		cout<<(mal[p]?"Bob\n":"Alice\n");
		fore(i,0,(1<<nn)) g[i].clear();
		fore(i,0,(1<<nn)) G[i].clear();
		mal&=cer;
		}
	return 0;
}
/*
1
3 4
111
111
==.
.==
..=
=..
(m)a 0 le corresponde 3 match con0
(m)a 1 le corresponde 5 match con0
(m)a 2 le corresponde 6 match con0

*/