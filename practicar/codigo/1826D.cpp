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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5, INF=1e9;
typedef vector<ii> node;

node oper(node &a, node &b){
	/*cout<<"oper {";
	for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"} {";
	for(auto i:b)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"}"<<endl;*/
	node c;
	ll l=0,r=0;
	while(SZ(c)<3){
		if(l<3&&(r==3||a[l]>=b[r])){
			if(!SZ(c)||a[l]!=c.back())c.pb(a[l]);
			l++;
		}
		else {
			if(!SZ(c)||b[r]!=c.back())c.pb(b[r]);
			r++;
		}
	}
	return c;
}

const ll K=17;//K such that 2^k>n
node st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]={{a[i],i},{-INF,-1},{-INF,-2}};
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
node st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

ll n;
//STree st(n);
ll cost(ll l, ll r){
	if(l>=r)return -INF;
	ll res=-(r-l-1);
	for(auto i:st_query(l,r))res+=i.fst;
	return res;
}

ll dp[MAXN];

void dnc(ll l, ll r, ll s, ll e){
	ll m=(l+r)/2;
	ll &res=dp[m];
	ll opt=s;
	res=-INF;
	fore(i,s,e)if(cost(i,m+1)>=res){
		opt=i,res=cost(i,m+1);
	}
	if(l+1!=r){
		dnc(l,m,s,opt+1);
		dnc(m,r,opt,e);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		st_init(a);
		//st=STree(n);
		//fore(i,0,n)st.upd(i,a[i]);
		dnc(0,n,0,n);
		ll res=-INF;
		fore(i,0,n)res=max(res,dp[i]);//,cout<<i<<": "<<dp[i]<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
