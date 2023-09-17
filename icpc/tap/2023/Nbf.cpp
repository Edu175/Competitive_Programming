#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<vector<ll>>sums={
	{0,1,0,0,1},
	{0,0,1,1,0},
	{0,1,2,0,0},
	{0,3,1,0,0},
	{0,2,0,1,0},
	{0,1,0,3,0},
	{0,5,0,0,0},
	{0,0,5,0,0},
	{0,0,0,5,0},
	{0,0,0,0,5}
};

ll solve(vector<ll>c){
	vector<ll>p;
	fore(i,0,SZ(sums))p.pb(i);
	//imp(c);
	ll res=0;
	do{
		//ll db=0;
		//if(p==vector<ll>({0,1,4,5,6,3,2,7,8,9}))db=1;
		vector<ll>ci=c;
		ll resi=0;
		fore(i,0,SZ(sums)){
			ll x=2e5+5;
			fore(j,1,5)if(sums[p[i]][j])x=min(x,ci[j]/sums[p[i]][j]);
			/*if(db){
				cout<<p[i]<<": "; imp(sums[p[i]]);
				cout<<": "<<x<<"\n\n";
			}*/
			if(!x)continue;
			resi+=x;
			fore(j,1,5)ci[j]-=x*sums[p[i]][j];
		}
		//if(resi==6){imp(p); cout<<resi<<"\n";return res;}
		res=max(resi,res);
	}
	while(next_permutation(ALL(p)));
	return res;
}

int main(){FIN;
	ll res=0;
	ll n; cin>>n;
	vector<ll>c(5);
	fore(i,0,n){
		ll x; cin>>x;
		c[x%5]++;
	}
	//imp(c);
	res+=c[0]; c[0]=0;
	ll add=solve(c);
	fore(i,1,3)swap(c[i],c[5-i]);
	add=max(add,solve(c));
	cout<<res+add<<"\n";
	return 0;
}
