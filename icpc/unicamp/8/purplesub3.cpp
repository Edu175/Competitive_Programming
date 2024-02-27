#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(sh i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" ";
using namespace std;
typedef long long ll;
typedef short sh;
typedef pair<ll,ll> ii;
const ll MAXN=65,M=21,L=6;

ll n,l;
sh a[MAXN],to[MAXN][M];

int Hash(pair<vector<sh>,pair<sh,bool>> data){
	auto [v,p]=data;
	auto [j,b]=p;
	ll h=0;
	for(auto i:v)h*=21,h+=i;
	h*=MAXN,h+=j;
	h*=2; h+=b;
	return h;
}

map<int,ll>dp;

ll f(vector<sh>v, sh j, bool b){
	int key=Hash({v,{j,b}});
	if(dp.count(key))return dp[key];
	ll &res=dp[key];
	if(j==n)return res=b;
	res=b;//f(v,j+1,b);
	//cout<<"enter "<<j<<": {";imp(v); cout<<"} "<<b<<"\n";
	fore(x,1,M){
		sh nj=to[j][x];
		if(nj==n)continue;
		//cout<<"j "<<j<<" "<<x<<" "<<b<<": "<<nj+1<<"\n";
		if(b){
			res+=f({},nj+1,b);
			continue;
		}
		auto vi=v;
		sh lwb=lower_bound(ALL(v),x)-v.begin();
		if(lwb>=SZ(v))vi.pb(x);
		else vi[lwb]=x;
		//cout<<"vi "<<SZ(vi)<<"\n";
		if(SZ(vi)>=l)res+=f({},nj+1,1);
		else res+=f(vi,nj+1,b);
	}
	//cout<<"out "<<j<<": {";imp(v); cout<<"} "<<b<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	cin>>l;
	fore(i,0,n)fore(v,0,M){
		ll nj=n;
		fore(j,i,n)if(a[j]==v){nj=j;break;}
		to[i][v]=nj;
		
	}
	cout<<f({},0,0)<<"\n";
	return 0;
}
