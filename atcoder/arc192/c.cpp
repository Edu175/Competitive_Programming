#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5005;

ll info[MAXN][MAXN];
ll ask(ll s, ll t){
	if(s>t)swap(s,t);
	auto &ret=info[s][t];
	if(ret!=-1)return ret;
	cout<<"? "<<s+1<<" "<<t+1<<endl;
	cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

ll n;
pair<vv,vv> solve(){
	vv a(n),p(n);
	ll mx=1;
	fore(i,1,n)if(ask(0,i)>ask(0,mx))mx=i;
	vector<ii> ind={{0,mx}};
	fore(i,0,n)if(i!=mx)ind.pb({ask(mx,i),i});
	sort(ALL(ind));
	a[mx]=ask(mx,ind.back().snd)-ask(ind.back().snd,ind[1].snd);
	
	a[ind[1].snd]=ind[1].fst-a[mx];
	for(ll i=n-1;i>=2;i--)a[ind[i].snd]=ind[i].fst-ind[i-1].fst;
	fore(i,0,n)p[ind[i].snd]=i;
	if(p[0]>p[1])reverse(ALL(ind));
	fore(i,0,n)p[ind[i].snd]=i;
	
	vv b(n);
	fore(i,0,n)b[p[i]]=a[i];
	return {p,b};
}


int main(){FIN;
	mset(info,-1);
	cin>>n;
	auto [p,a]=solve();
	cout<<"! ";
	for(auto i:p)cout<<i+1<<" ";
	for(auto i:a)cout<<i<<" ";
	cout<<endl;
	return 0;
}
