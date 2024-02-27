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
typedef long long ll;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("Ofast") // may lead to precision errors

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=55;
vector<int>a;
int n;
typedef ll node;

int lis(vector<int>&a){
	vector<int>v;
	fore(i,0,n){
		int lwb=upper_bound(ALL(v),a[i])-v.begin();
		if(lwb>=SZ(v))v.pb(a[i]);
		else v[lwb]=a[i];
	}
	return SZ(v);
}

int value(node x){ //valor a minimizar
	vector<int>rev,b=a;
	fore(i,0,n)if((x>>i)&1)rev.pb(a[i]);
	fore(i,0,n)if((x>>i)&1){
		b[i]=rev.back();
		rev.pop_back();
	}
	return -lis(b);
}
node vecino(node x){ //estado vecino, diametro del grafo chico <=50 o por ahi
	return x^(1ll<<(rand()%n));
}
node random_state(){ //random initial state
	node x=0;
	fore(i,0,n)x|=(rand()&1ll)<<i;
	return x;
}
/*double temp(double p){
	
}*/
double P(ll old, ll now, double t){
	if(now<old)return 1.0;
	return exp((old-now)/t);
}
double t=1e9; //temperature, 1e9 or 1e5
node simulated_annealing(){
	ll sd; srand((ll)&sd);
	node s=random_state();
	
	node best=s;
	//ll steps=0;
	while(clock()<=1.99*CLOCKS_PER_SEC){ //time limit 2sec
		//double t=temp((clock()/(double)CLOCKS_PER_SEC)/1.99);
		node next=vecino(s);
		if(value(s)<value(best))best=s;
		if(P(value(s),value(next),t)*RAND_MAX>=rand())s=next;
		t*=0.9999;
		//steps++;
	}
	//cout<<"total steps "<<steps<<"\n";
	return best;
}

int main(){FIN;
	ifstream cin;   cin.open("subrev.in", ios::in);
	ofstream cout; cout.open("subrev.out", ios::out);
	//cout<<(-1ull)<<"\n";
	cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	ll ret=simulated_annealing();
	cout<<-value(ret)<<"\n";
	return 0;
}
