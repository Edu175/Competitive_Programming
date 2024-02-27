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
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
int s[MAXN],a[2][MAXN];
int n;
int cost(const int &i){
	return (s[i]<2?a[s[i]][i]:0);
}
ll v;
void change(const int &i, const int &j){
	v-=cost(i)+cost(j);
	swap(s[i],s[j]);
	v+=cost(i)+cost(j);
}
ll SA(){
	int sd; srand((ll)&sd);
	random_shuffle(s,s+n);
	fore(i,0,n)if(s[i]<2)v+=cost(i);
	ll best=v;
	double t=1e5;
	while(clock()<=0.99*CLOCKS_PER_SEC){
		int i=rand()%n,j=rand()%n;
		ll old=v;
		change(i,j);
		if(v<best)best=v;
		if(v>=old&&exp((old-v)/t)<(double)rand()/RAND_MAX)change(i,j);
		t*=0.999997;
	}
	cout<<t<<endl;
	return best;
}
int main(){FIN;
	ll c,d; cin>>c>>d>>n;
	fore(i,0,n)cin>>a[0][i]>>a[1][i],a[0][i]*=-1,a[1][i]*=-1;
	fore(i,0,c)s[i]=0;
	fore(i,c,c+d)s[i]=1;
	fore(i,c+d,n)s[i]=2;
	cout<<-SA()<<"\n";
	return 0;
}
