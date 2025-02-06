#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool match(string a, string b, ll d){
	fore(i,d,SZ(a)){
		ll j=i-d;
		if(j<SZ(b)&&a[i]!=b[j])return 0;
	}
	return 1;
}
const ll MAXN=1005;

vv g[MAXN],wh[MAXN];
ll valid[MAXN];
ll vis[MAXN];
ll fa[MAXN];

void dfs(ll x){
	if(!valid[x])return;
	// cout<<"dfs "<<x<<"\n";
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		fa[y]=x;
		dfs(y);
	}
}
void compose(auto &a, vv b){
	auto c=a;
	fore(i,0,SZ(a))c[i]=a[b[i]];
	a=c;
}
int main(){
	JET
	ll h,n; cin>>h>>n;
	vector<pair<ll,string>>a(n);
	vector<ii>rans(n);
	fore(i,0,n){
		cin>>a[i].fst>>a[i].snd;
		a[i].fst--;
		rans[i]={a[i].fst,a[i].fst+SZ(a[i].snd)};
	}
	vv per(n); iota(ALL(per),0);
	sort(ALL(per),[&](ll i, ll j){
		return ii({rans[i].fst,-rans[i].snd})<
			   ii({rans[j].fst,-rans[j].snd});
	});
	compose(a,per);
	compose(rans,per);
	
	// for(auto i:per)cout<<i<<" ";;cout<<endl;
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	// for(auto i:rans)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	
	fore(i,0,2*n)valid[i]=1;
	ll pa=0;
	fore(i,1,n){
		ll fg=rans[i].snd<=rans[pa].snd; // useless i
		// cout<<i<<": "<<fg<<"\n";
		auto [p,l]=a[pa];
		auto [q,r]=a[i];
		ll d=q-p;
		vv alg(2);
		fore(p,0,2)fore(q,0,2){
			if(p)reverse(ALL(l));
			if(q)reverse(ALL(r));
			
			if(match(l,r,d)){
				if(fg){
					alg[p]=1;
					wh[2*pa+p].pb(2*i+q);
				}
				else g[2*pa+p].pb(2*i+q);
			}
			if(p)reverse(ALL(l));
			if(q)reverse(ALL(r));
		}
		if(fg){
			fore(p,0,2)valid[2*pa+p]&=alg[p];
		}
		else pa=i;
	}
	// fore(i,0,2*n)cout<<valid[i]<<" ";;cout<<"\n";
	// cout<<pa<<" pa\n";
	fa[0]=-1;
	dfs(0);
	fa[1]=-1;
	dfs(1);
	ll x=2*pa;
	if(!vis[x])x=2*pa+1;
	if(!vis[x]){
		cout<<"Fail\n";
		return 0;
	}
	vv us(n);
	while(x!=-1){
		for(auto y:wh[x])us[y/2]=y%2;
		us[x/2]=x%2;
		// cout<<x<<"\n";
		x=fa[x];
	}
	// for(auto i:us)cout<<i<<" ";;cout<<"\n";
	string ret(h,'T');
	vv vis(h);
	fore(i,0,n){
		auto [p,s]=a[i];
		if(us[i])reverse(ALL(s));
		fore(j,0,SZ(s)){
			if(vis[j+p])assert(ret[j+p]==s[j]);
			ret[j+p]=s[j];
		}
		// cout<<p<<": "<<s<<"\n";
	}
	cout<<ret<<"\n";
	return 0;
}