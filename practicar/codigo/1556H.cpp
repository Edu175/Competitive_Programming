#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(short i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<vector<pair<short,short>>,int> node;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=55;
int g[MAXN][MAXN];
short d[10];
short n,k;
int value(node &a){
	return a.snd;
}
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(short x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(short x, short y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<short>per;
node vecino(node a){
	short idx=rand()%SZ(a.fst);
	uf_init();
	vector<short>deg(k);
	fore(i,0,SZ(a.fst))if(i!=idx){
		auto [u,v]=a.fst[i];
		uf_join(u,v);
		if(u<k)deg[u]++;
		if(v<k)deg[v]++;
	}
	random_shuffle(ALL(per));
	short u=-1,v=-1;//,did=0;
	fore(i,0,n)fore(j,i+1,n){
		u=per[i],v=per[j];
		if(uf_find(u)!=uf_find(v)&&(u>=k||deg[u]<d[u])&&(v>=k||deg[v]<d[v])){
			//did=1;
			goto afuera;
		}
	}
	afuera:
	//assert(did);
	a.snd+=-g[a.fst[idx].fst][a.fst[idx].snd]+g[u][v];
	a.fst[idx]={u,v};
	return a;
}
node random_state(){
	/*node ret;
	fore(i,1,n)ret.fst.pb({k,i}),ret.snd+=g[k][i];*/
	node a;
	uf_init();
	vector<short>deg(k);
	fore(_,0,n-1){
		random_shuffle(ALL(per));
		short u=-1,v=-1;
		fore(i,0,n)fore(j,i+1,n){
			u=per[i],v=per[j];
			if(uf_find(u)!=uf_find(v)&&(u>=k||deg[u]<d[u])&&(v>=k||deg[v]<d[v])){
				goto out;
			}
		}
		out:
		a.snd+=g[u][v];
		a.fst.pb({u,v});
		uf_join(u,v);
		if(u<k)deg[u]++;
		if(v<k)deg[v]++;
	}
	return a;
}
/*double temp(double p){
	
}*/
double P(int old, int now, double t){
	if(now<old)return 1.0;
	return exp((old-now)/t);
}
double t=1e5;
node simulated_annealing(){
	ll seed; srand((ll)&seed);
	node s=random_state();
	node best=s;
	//ll steps=0;
	while(clock()/(double)CLOCKS_PER_SEC<=5.99){
		//cout<<clock()/(double)CLOCKS_PER_SEC<<" ";
		//double t=temp((clock()/(double)CLOCKS_PER_SEC)/1.99);
		node next=vecino(s);
		if(value(s)<value(best))best=s;
		if(P(value(s),value(next),t)>=(double)rand()/RAND_MAX)s=next;
		t*=0.99999;
		//cout<<clock()/(double)CLOCKS_PER_SEC<<" temp "<<t<<"\n";
		//steps++;
	}
	//cout<<"total steps "<<steps<<"\n";
	return best;
}


int main(){FIN;
	cin>>n>>k;
	fore(i,0,k)cin>>d[i];
	fore(i,0,n)fore(j,i+1,n){
		cin>>g[i][j];
		g[j][i]=g[i][j];
	}
	fore(i,0,n)per.pb(i);
	node ret=simulated_annealing();
	/*for(auto [u,v]:ret.fst){
		cout<<u<<" "<<v<<" "<<g[u][v]<<"\n";
	}
	cout<<"\n";*/
	//cout<<t<<"\n";
	cout<<ret.snd<<"\n";
	return 0;
}
