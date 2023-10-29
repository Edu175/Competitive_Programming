#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,oia=b;i<oia;++i)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=3e5+5,INF=5*MAXN;

vector<ll>g[MAXN];
ll id[MAXN];

ll cnt(ll x,ll d,ll e){
	if(e==d)return INF;
	ll res=0;
	if(id[x]!=d)res++;
	ll ch=0;
	fore(i,0,3)if(i!=e&&i!=d)ch=i;
	for(auto i:g[x]){
		res+=cnt(i,ch,e);
	}
	return res;
}

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("repetidores.in", ios::in);
	cout.open("repetidores.out", ios::out);
	ll n; cin>>n;
	ll p[n];
	mset(p,-1);
	fore(i,0,n){
		ll x; cin>>x; x--;
		char c; cin>>c;
		id[x]=c-'A';
		ll m; cin>>m;
		fore(i,0,m){
			ll y; cin>>y; y--;
			g[x].pb(y);
			p[y]=x;
		}
	}
	ll s=0,e=-1,res=INF;
	while(p[s]!=-1)s=p[s];
	fore(i,0,3){
		fore(j,0,3){
			ll resi=cnt(s,j,i);
			if(resi<res)e=i,res=resi;
		}
	}
	cout<<res<<" ";
	vector<char>r;
	fore(i,0,3)if(i!=e)r.pb('A'+i);
	cout<<r[0]<<" "<<r[1]<<"\n";
	assert(res!=INF&&e!=-1);
	//assert(n!=13);
	return 0;
}
