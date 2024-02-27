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
const int MAXN=35;
int n,p;
ll s[MAXN];
ll sum[10];
ll tot;
vector<int> id(MAXN);
bool dbg=0;
int value(){ //valor a minimizar
	/*if(dbg){
		cout<<"!!!!!!\n";
		cout<<"value "<<p<<"\n";
		fore(i,0,n)cout<<i<<": "<<id[i]<<" "<<sum[i]<<"\n";
	}*/
	ll v=tot,mx=0; // sum[i]-v has to be non-positive
	for(int i=32-__builtin_clz(n);i;i--){
		v-=sum[i];
		mx=max(mx,(sum[i]-v)*(i+1));
		//if(dbg)cout<<"v "<<i<<" "<<sum[i]<<" "<<v<<"\n";
		//if(!(v>=sum[i]))return (i+1);
	}
	//cout<<"passed\n";
	return mx;
}
void swp(int i, int j){
	sum[id[i]]+=s[j]-s[i],sum[id[j]]+=s[i]-s[j];
	swap(id[i],id[j]);
}
void random_state(){ //random initial state
	//cout<<"random state "<<p<<" "<<n<<"\n";
	id[p]=0;
	vector<int> a={p};
	fore(i,0,n)if(i!=p)a.pb(i);
	random_shuffle(a.begin()+1,a.end());
	fore(i,1,n)id[a[i]]=32-__builtin_clz(i);
	fore(i,0,10)sum[i]=0;
	fore(i,0,n)sum[id[i]]+=s[i];
	//fore(i,0,n)cout<<i<<" "<<s[i]<<": "<<id[i]<<" "<<sum[id[i]]<<"\n";
}
double P(int old, int now, double t){
	if(now<old)return 1.0;
	return exp((old-now)/t);
}
//double tim;

int rnd(){
	int r=rand()%(n-1);
	if(r>=p)r++;
	return r;
}
int simulated_annealing(){
	double t=1e9; //temperature, 1e9 or 1e5
	random_state();
	int best=value();
	ll steps=0;
	while(best>0&&clock()<=1.99*CLOCKS_PER_SEC){ //time limit 2sec
		steps++;
		int i=rnd(),j=rnd();
		int vs=value();
		swp(i,j);
		if(vs<best)best=vs;
		if(P(vs,value(),t)<(double)rand()/RAND_MAX)swp(i,j);
		t*=0.999995;
	}
	cout<<p<<": "<<t<<" steps "<<steps<<" = "<<best<<"\n";
	return best;
}

int main(){FIN;
	int seed; srand((ll)&seed);
	//cout<<__builtin_clz(1)<<"\n";
	cin>>n;
	fore(i,0,n)cin>>s[i],tot+=s[i];
	vector<bool>res(n);
	//tim=(1.9*CLOCKS_PER_SEC-clock())/32.0;
	//cout<<tim<<"\n";
	vector<pair<int,int>>per;
	fore(i,0,n)per.pb({s[i],i});
	//random_shuffle(ALL(per));
	sort(ALL(per)); reverse(ALL(per));
	ll flag=1;
	for(auto [si,i]:per){
		if(!flag){res[i]=0;continue;}
		//tim=(1.99*CLOCKS_PER_SEC-clock())/(n-j);
		//cout<<"\ntim "<<i<<": "<<(1.99*CLOCKS_PER_SEC-clock())/(n-j)/CLOCKS_PER_SEC<<"\n";
		p=i;flag&=res[i]=simulated_annealing()<=0;
	}
	/*dbg=1;
	id={4,2,4,3,3,2,4,1,0,4,3,4,4,3,4,4};
	fore(i,0,10)sum[i]=0;
	fore(i,0,n)sum[id[i]]+=s[i];
	cout<<value()<<"\n";*/
	fore(i,0,n)cout<<res[i];;cout<<"\n";
	fore(i,0,n)cout<<i%10;;cout<<"\n";
	return 0;
}
