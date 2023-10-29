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

//(min, increasing insert coefficents, non increasing queries, online)
//for maximum just change the sign of lines (and query result)
ll idiv(ll a, ll b){ //int division
	if((a<0)^(b<0))return (a+b-1)/b; //ceil
	return a/b; //floor
}
struct ln{
	ll a,b;
	ln(ll a, ll b):a(a),b(b){}
	ll eq(ll x){return a*x+b;}
	pair<ll,ll> operator%(ln l){
		ll x=idiv(b-l.b,l.a-a);
		return {x,eq(x)};
	}
};
deque<ln>cht;
ll query(ll x){
	ln l=cht.back(); cht.pop_back();
	while(SZ(cht)&&l.eq(x)>=cht.back().eq(x))l=cht.back(),cht.pop_back();
	cht.pb(l);
	cout<<"qu "<<x<<": ";
	for(auto i:cht)cout<<i.a<<"x+"<<i.b<<" ";
	cout<<"\n= "<<cht.back().eq(x)<<"\n";
	return cht.back().eq(x);
}
void insert(ln l){
	if(!SZ(cht)){
		cht.pb(l);
		return;
	}
	ln m=cht.front(); cht.pop_front();
	while(SZ(cht)&&((l%m).fst>(m%cht.front()).fst/*||l%m==m%cht.front()*/))
		m=cht.front(),cht.pop_front();
	cht.push_front(m), cht.push_front(l);
	cout<<"in: "<<l.a<<"x+"<<l.b<<": ";
	for(auto i:cht)cout<<i.a<<"x+"<<i.b<<" ";
	cout<<"\n";
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll>sp(n+1),sm(n+1);
	fore(i,1,n+1){
		sp[i]=sp[i-1]+a[i-1];
		sm[i]=sm[i-1]+a[i-1]*i;
	}
	imp(sp); imp(sm);
	fore(l,0,n){
		cout<<l<<"x+"<<-(l*sp[l]-sm[l])<<"\n";
		insert(ln(l,-(l*sp[l]-sm[l])));
	}
	for(auto i:cht)cout<<i.a<<"x+"<<i.b<<" ";
	cout<<"\n";
	ll res=0;
	vector<pair<ll,ll>>qu;
	fore(r,1,n+1)qu.pb({sp[r],sm[r]});
	sort(ALL(qu)); reverse(ALL(qu));
	for(auto i:qu){
		ll y=-query(i.fst);
		res=max(res,y+i.snd);
		cout<<"osea "<<y<<"+"<<i.snd<<" = "<<y+i.snd<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
