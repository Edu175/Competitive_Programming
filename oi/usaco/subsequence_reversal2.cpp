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
typedef short ll;
typedef long long LL;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
vector<ll>a;
ll n;

inline ll lis(vector<ll>&a){
	vector<ll>v;
	fore(i,0,n){
		ll lwb=upper_bound(ALL(v),a[i])-v.begin();
		if(lwb>=SZ(v))v.pb(a[i]);
		else v[lwb]=a[i];
	}
	return SZ(v);
	/*vector<ll>dp(n,1);
	for(ll i=n-1;i>=0;i--)fore(j,i+1,n)if(a[i]<=a[j]){
		dp[i]=max(dp[i],dp[j]+1);
	}
	return dp[0];*/
}

ll value(vector<bool>&x){ //valor a minimizar
	vector<ll>p,b=a;
	fore(i,0,n)if(x[i])p.pb(i);
	fore(i,0,SZ(p)/2)swap(b[p[i]],b[p[SZ(p)-1-i]]);
	return -lis(b);
}

double t=1e9; //temperature, 1e9 or 1e5
ll simulated_annealing(){
	ll sd; srand((LL)&sd);
	vector<bool>s(n);
	fore(i,0,n)s[i]=rand()&1;
	ll res=0,best=0;
	while(clock()/(double)CLOCKS_PER_SEC<=1.99){ //t>1e-5 time limit 2sec
		ll pos=rand()%n;
		s[pos]=1-s[pos];
		ll resi=value(s);
		best=min(best,resi);
		if(resi<res)res=resi;
		else{
			if(exp((res-resi)/t)>=(double)rand()/RAND_MAX)res=resi;
			else s[pos]=1-s[pos];
			//me quedo
		}
		t*=0.99999;
	}
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
	//cout<<t<<" t\n";
	cout<<-ret<<"\n";
	return 0;
}
