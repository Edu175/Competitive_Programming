#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct rec{
	ll i0,i1,j0,j1;
	//rec(){}
};
rec va={0,0,0,0};

ll rnd(ll l, ll r){
	if(r-l==0)return l;
	return rand()%(r-l)+l;
}

int main(){FIN;
	ll N; srand((ll)&N); cin>>N;
	ll n=rand()%N+1; cout<<n<<"\n";
	vector<ll>a;
	fore(i,0,n)a.pb(i);
	random_shuffle(ALL(a));
	for(auto i:a)cout<<i+1<<" ";;cout<<"\n";
	ll Q; cin>>Q;
	ll q=rand()%Q+1; cout<<q<<"\n";
	rec qs[q+1]={};
	qs[0]={0,n,0,n};
	fore(i,1,q+1){
		ll t=rand()%2+1,s=rand()%i,x;
		qs[i]=qs[s];
		rec &r=qs[i];
		if(rand()%50==1)x=rand()%n;
		else if(t==1)x=rnd(r.i0,r.i1),qs[s].i1=x,r.i0=x;
		else x=rnd(r.j0,r.j1),qs[s].j1=x,r.j0=x;
		cout<<t<<" "<<s<<" "<<x<<"\n";
	}
	return 0;
}
