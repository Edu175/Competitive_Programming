#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=35;
int n,p;
ll s[MAXN];
typedef vector<int> node;
int value(node a){ //valor a minimizar
	int n=SZ(a);
	vector<ll>sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+s[a[i-1]];
	for(int i=32-__builtin_clz(SZ(a)),k=n/2;k>=1;k/=2,i--){
		if(sp[k]<sp[2*k]-sp[k])return i;
	}
	return 0;
}
node vecino(node a){ //estado vecino, diametro del grafo chico <=50 o por ahi
	swap(a[rand()%(SZ(a)-1)+1],a[rand()%(SZ(a)-1)+1]);
	return a;
}
node random_state(){ //random initial state
	node ret={p};
	fore(i,0,n)if(i!=p)ret.pb(i);
	random_shuffle(ret.begin()+1,ret.end());
	return ret;
}
double P(int old, int now, double t){
	if(now<old)return 1.0;
	return exp((old-now)/t);
}
double tim;
node simulated_annealing(){
	double t=1e5; //temperature, 1e9 or 1e5
	int seed; srand((ll)&seed);
	double start=clock();
	node s=random_state();
	node best=s;
	while(clock()-start<=tim){ //time limit 2sec
		node next=vecino(s);
		int vs=value(s);
		if(vs<value(best))best=s;
		if(P(vs,value(next),t)>=(double)rand()/RAND_MAX)s=next;
		t*=0.99998;
	}
	cout<<t<<endl;
	return best;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>s[i];
	vector<bool>res(n);
	tim=(1.8*CLOCKS_PER_SEC-clock())/32.0;
	//cout<<tim<<"\n";
	fore(i,0,n){
		p=i;
		node ret=simulated_annealing();
		res[i]=value(ret)==0;
		if(i==8){
			imp(ret);
			vector<ll>pos(n);
			fore(i,0,n)pos[ret[i]]=i;
			imp(pos);
			fore(i,0,n)cout<<32-__builtin_clz(pos[i])<<" ";
			cout<<" = "<<value(ret)<<"\n";
		}
	}
	fore(i,0,n)cout<<res[i];;cout<<"\n";
	//cout<<res[16]<<"\n";
	return 0;
}
