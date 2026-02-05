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
typedef unsigned long long ull;
typedef pair<ull,ull> ii;
typedef vector<ll> vv;

struct node{
	ll sum,prod,cant,bad; // bad: si sum aumenta, desaparece. sino, hay que tenerlo en cuenta para el cant
};

void merge(node &a, node b){
	if(b.cant==0)return;
	if(a.cant==0){a=b;return;}
	if(a.sum==b.sum){
		if(a.prod>b.prod)swap(a,b);
		if(a.prod==b.prod)a.cant+=b.cant,a.bad+=b.bad;
		else a.bad+=b.bad+b.cant;
		return;
	}
	if(a.sum<b.sum)swap(a,b);
	assert(a.prod>=b.prod);
}

vv mem[10][2200][2];
vector<vv> nums={
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
bool has(vv &est, ll d){
	ll fg=1;
	fore(i,0,7)fg&=est[i]==2||est[i]==nums[d][i];
	return fg;
}
vv get(ll c, vv est, ll bo){
	ll hsh=0;
	fore(i,0,SZ(est))hsh=3*hsh+est[i];
	auto &ret=mem[c][hsh][bo];
	if(SZ(ret))return ret;
	ret=vv(10);
	fore(mk,0,1ll<<7)if(__builtin_popcountll(mk)==c){
		vv now=est;
		fore(i,0,7)if(mk>>i&1)now[i]=2;
		if(bo!=has(now,0))continue;
		ll otr=0;
		fore(d,1,10)otr+=has(now,d);
		ret[otr]++;
	}
	while(SZ(ret)>1&&!ret.back())ret.pop_back();
	// cout<<"get "<<c<<" ";
	// for(auto i:est)cout<<i;
	// cout<<" "<<bo<<endl;
	// imp(ret)
	// cout<<"\n\n";
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<vv> panel(n,vv(7));
		fore(i,0,7){
			string s; cin>>s;
			if(i == 0) for(int j = 1;j<5*n;j+=5) panel[j/5][0] = (s[j]!='W' ? s[j] - '0' : 2);
			if(i == 1) for(int j = 0;j<5*n;j+=5) panel[j/5][1] = (s[j]!='W' ? s[j] - '0' : 2);
			if(i == 1) for(int j = 3;j<5*n;j+=5) panel[j/5][2] = (s[j]!='W' ? s[j] - '0' : 2);
			if(i == 3) for(int j = 1;j<5*n;j+=5) panel[j/5][3] = (s[j]!='W' ? s[j] - '0' : 2);
			if(i == 4) for(int j = 0;j<5*n;j+=5) panel[j/5][4] = (s[j]!='W' ? s[j] - '0' : 2);
			if(i == 4) for(int j = 3;j<5*n;j+=5) panel[j/5][5] = (s[j]!='W' ? s[j] - '0' : 2);
			if(i == 6) for(int j = 1;j<5*n;j+=5) panel[j/5][6] = (s[j]!='W' ? s[j] - '0' : 2);
		}
		// fore(i,0,n){
		// 	fore(j,0,7)cout<<panel[i][j]<<"|";
		// 	cout<<" ";
		// }
		// cout<<endl;
		auto dodp=[&](ll mk)-> ii { // sum,cant
			// sum prod cant
			vector<vector<node>> dp(n+1,vector<node>(k+1,{0,1,1,0}));
			ll _k=k;
			for(ll i=n-1;i>=0;i--)fore(k,0,_k+1){
				auto &res=dp[i][k];
				res.cant=0;
				ll bo=mk>>i&1;
				fore(c,0,7+1){
					auto coefs=get(c,panel[i],bo);
					if(k-c<0)continue;
					fore(otr,0,SZ(coefs)){
						node cur=dp[i+1][k-c];
						cur.cant*=coefs[otr];
						ll del=cur.prod*otr;
						cur.sum+=del;
						cur.prod*=(otr+bo);
						if(del)cur.bad=0; // desaparece
						merge(res,cur);
					}
				}
				// cout<<i<<" "<<k<<": "<<res.sum<<","<<res.prod<<" "<<res.cant<<","<<res.bad<<"\n";
			}
			node res=dp[0][_k];
			// node res; res[2]=0;
			// fore(k,0,_k+1)merge(res,dp[0][k]);
			if(mk&1)res.sum++;
			res.cant+=res.bad;
			// cout<<"mk "<<mk<<": "<<res.sum<<" "<<res.cant<<"\n";
			return {res.sum,res.cant};
		};
		ii res; // de ull actually
		ll did=0;
		fore(mk,0,1ll<<n){
			auto cur=dodp(mk);
			if(cur.snd==0)continue;
			if(!did||cur.fst>res.fst)res=cur;
			else if(cur.fst==res.fst)res.snd+=cur.snd;
			did=1;
		}
		cout<<res.fst<<" "<<res.snd<<"\n";
	}
	return 0;
}
