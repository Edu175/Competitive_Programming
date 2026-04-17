#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kjfg:v)cout<<kjfg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	ll N,V; cin>>N>>V;
	cout<<"4\n";
	ll n=rng()%N+1;
	cout<<n<<"\n";
	if(n==1){
		cout<<"1 "<<rng()%V<<"\n";
		return 0;
	}
	vector<ll>per,p;
	fore(i,0,V)per.pb(i);
	fore(i,0,n)p.pb(i);
	shuffle(ALL(per),rng);
	shuffle(ALL(p),rng);
	vector<ll>d(n),t(n);
	ll e=rng()%(n+1),mn=-1,mx=-1;
	fore(i,0,n){
		d[p[i]]=per[i];
		if(mx==-1||per[i]>d[mx])mx=p[i];
		if(mn==-1||per[i]<d[mn])mn=p[i];
		
	}
	fore(i,0,e)t[p[i]]=0;
	fore(i,e,n)t[p[i]]=1;
	if(mx==0){
		swap(d[0],d[1]);
		mx=1;
	}
	t[mn]=t[0]=0;
	t[mx]=1;
	fore(i,0,n){
		cout<<t[i]+1<<" "<<d[i]<<"\n";
	}
	return 0;
}