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
const ll MAXN=1005;

ll ask(vector<ll>a){
	if(!SZ(a))return 0;
	cout<<"? "<<SZ(a)<<" ";
	for(auto i:a)cout<<i+1<<" ";
	cout<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

ll qs[15];
vector<ll>vs[15];

int main(){FIN;
	ll n; cin>>n;
	vector<ll>p(7,0);
	fore(i,0,6)p.pb(1);
	ll i=0;
	vector<ll>per[n];
	do{
		per[i]=p;
		fore(j,0,SZ(p))if(p[j])vs[j].pb(i);
		i++;
	}
	while(next_permutation(ALL(p))&&i<n);
	fore(i,0,13)qs[i]=ask(vs[i]);
	vector<ll>res(n);
	fore(i,0,n){
		fore(j,0,13)if(!per[i][j])res[i]|=qs[j];
	}
	cout<<"! ";
	for(auto i:res)cout<<i<<" ";;cout<<endl;
	return 0;
}
