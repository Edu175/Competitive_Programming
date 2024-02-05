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

const ll K=18;//K such that 2^k>n
#define oper max
ll st[K][1ll<<K];
void st_init(vector<ii> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i].fst;
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
ll lwb(ll s, ll e, ll x){
	ll l=s,r=e-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(st_query(s,m+1)>=x)r=m-1;
		else l=m+1;
	}
	return l;
}
bool cmp(ii a, ii b){return a.snd<b.snd;}
int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	sort(ALL(a),cmp);
	st_init(a);
	ll to[K][n+1];
	fore(k,0,K)to[k][n]=n;
	fore(i,0,n)to[0][i]=lwb(i,n,a[i].snd);
	fore(k,1,K)fore(i,0,n)to[k][i]=to[k-1][to[k-1][i]];
	/*fore(i,0,n){
		cout<<i<<": ";
		fore(k,0,5)cout<<to[k][i]<<" ";
		cout<<"\n";
	}*/
	while(q--){
		ll l,r; cin>>l>>r;
		ll x=lwb(0,n,l);
		if(x>=n||a[x].snd>r){
			cout<<"0\n";
			continue;
		}
		ll res=1;
		for(ll k=K-1;k>=0;k--)if(to[k][x]<n&&a[to[k][x]].snd<=r){
			res+=1ll<<k;
			x=to[k][x];
		}
		cout<<res<<"\n";
	}
	return 0;
}
