#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll idiv(ll a, ll b){ //int division
	if((a<0)^(b<0))return (a+b-1)/b; //ceil
	return a/b; //floor
}
struct ln{
	ll a,b;
	ln(ll a, ll b):a(a),b(b){}
	ll eq(ll x){return a*x+b;}
	ii operator%(ln l){
		ll x=idiv(b-l.b,l.a-a);
		return {x,eq(x)};
	}
};
deque<ln>cht;
ll query(ll x){
	ln l=cht.back(); cht.pop_back();
	while(SZ(cht)&&l.eq(x)>=cht.back().eq(x))l=cht.back(),cht.pop_back();
	cht.pb(l);
	return cht.back().eq(x);
}
void insert(ln l){
	if(!SZ(cht)){
		cht.pb(l);
		return;
	}
	ln m=cht.front(); cht.pop_front();
	while(SZ(cht)&&((l%m).fst>(m%cht.front()).fst||l%m==m%cht.front()))
		m=cht.front(),cht.pop_front();
	cht.push_front(m), cht.push_front(l);
}
ll n,c,h[MAXN];
ll dp[MAXN];
int main(){FIN;
	cin>>n>>c;
	fore(i,0,n)cin>>h[i];
	for(ll i=n-1;i>=0;i--){
		if(i==n-1)dp[i]=0;
		else dp[i]=query(h[i])+h[i]*h[i]+c;
		insert(ln(-2*h[i],h[i]*h[i]+dp[i]));
	}
	cout<<dp[0]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
