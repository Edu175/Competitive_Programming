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
const ll MAXN=255,INF=1e9;

ll n, a[MAXN],id[MAXN];
ii dp[MAXN][MAXN];

ii f(ll l, ll r){
	ii &res=dp[l][r];
	if(res.fst!=-1)return res;
	if(r-l==0)return res={0,0};
	res.fst=INF;
	fore(m,l,r){
		ll p=f(l,m).snd+f(m+1,r).snd+a[m];
		ll t=p+f(l,m).fst+f(m+1,r).fst;
		if(t<res.fst)res.snd=p,res.fst=t;
	}
	//cout<<l<<" "<<r<<": "<<res.fst<<" "<<res.snd<<"\n";
	return res;
}
string ans;
void build(ll l, ll r){
	ii &res=dp[l][r];
	if(r-l==0)return;
	fore(m,l,r){
		ll p=f(l,m).snd+f(m+1,r).snd+a[m];
		ll t=p+f(l,m).fst+f(m+1,r).fst;
		if(res.fst==t){
			ans+="(";
			build(l,m);
			ans+=to_string(id[m]);
			build(m+1,r);
			ans+=")";
			break;
		}
	}
	
}
int main(){FIN;
	ifstream cin;   cin.open("oficinas.in", ios::in);
	ofstream cout; cout.open("oficinas.out", ios::out);
	cin>>n;
	fore(i,0,n+3)fore(j,0,n+3)dp[i][j]={-1,-1};
	vector<ii>b(n);
	fore(i,0,n)cin>>b[i].fst>>b[i].snd;
	sort(ALL(b));
	fore(i,0,n)id[i]=b[i].fst,a[i]=b[i].snd;
	/*fore(i,0,n)cout<<id[i]<<" ";
	cout<<"\n";
	fore(i,0,n)cout<<a[i]<<" ";
	cout<<"\n";*/
	cout<<f(0,n).fst<<"\n";
	build(0,n);
	cout<<ans<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
