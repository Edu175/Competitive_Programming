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

double mini=5,maxi=-5;
double op(ll a, ll b, ll c){
	return double(a+b+c)/double(a*b*c);
}
void upd(ll a, ll b, ll c){
	maxi=max(maxi,op(a,b,c));
	mini=min(mini,op(a,b,c));
	//cout<<a<<" "<<b<<" "<<c<<": "<<op(a,b,c)<<" "<<(a+b+c)/(a*b*c)<<"\n";
}
int main(){FIN;
	cout<<fixed<<setprecision(15);
	ll n; cin>>n;
	ll a[n];
	vector<ll>neg,pos;
	fore(i,0,n){
		cin>>a[i];
		if(a[i]<0)neg.pb(a[i]);
		else pos.pb(a[i]);
	}
	sort(ALL(pos)); sort(ALL(neg));
	sort(a,a+n);
	fore(i,0,n-2)upd(a[i],a[i+1],a[i+2]);
	if(SZ(neg)&&SZ(pos)>=2){
		fore(i,0,SZ(pos)-1)
			upd(neg[0],pos[i],pos[i+1]),upd(neg.back(),pos[i],pos[i+1]);
		fore(i,0,SZ(neg))
			upd(pos[0],pos[1],neg[i]),upd(pos[SZ(pos)-2],pos[SZ(pos)-1],neg[i]);
	}
	if(SZ(pos)&&SZ(neg)>=2){
		fore(i,0,SZ(neg)-1)
			upd(pos[0],neg[i],neg[i+1]),upd(pos.back(),neg[i],neg[i+1]);
		fore(i,0,SZ(pos))
			upd(neg[0],neg[1],pos[i]),upd(neg[SZ(neg)-2],neg[SZ(neg)-1],pos[i]);
	}
	cout<<mini<<"\n"<<maxi<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
