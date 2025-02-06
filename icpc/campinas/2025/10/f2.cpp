#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct tre{
ll a,b,c;
tre(ll a, ll b, ll c): a(a),b(b),c(c) {}
tre() {}	
};
const ll MAXN=1e5+10;
tre dp[MAXN];
ll n,k;
vv a;
ll res=0, cnt=0;
bool check(ll h){
	fore(i,0,n) dp[i]=tre(-1,-1,-1);
	dp[n]=tre(0,0,0);
	ll cant=0;
	cout<<"h="<<h<<":\n";
	for(ll i=n; i--;){
		auto [tot,s,c]=dp[i+1];
		if(tot+a[i]+h<tot-s*c+(s+a[i])*(c+1)){
			dp[i]=tre(tot+a[i]+h,a[i],1);
			cant++;
			cout<<"agregamos en "<<i<<"  "<<a[i]<<"\n";
			cout<<"tot="<<tot<<" "<<"s="<<s<<" "<<"c="<<c<<"\n";
			cout<<"pasamos a:"<<"tot="<<tot+a[i]+h<<" "<<"s="<<a[i]<<" "<<"c="<<1<<"\n";
		}
		else{
			dp[i]=tre(tot-s*c+(s+a[i])*(c+1),s+a[i],c+1);
		}
	}
	cnt=cant;
	cout<<"cant="<<cant<<"\n";
	res=dp[0].a;
	return cant>k;
}
const ll INF=1e18;
int main(){
	TUCUTUCUTUCUTUCU
	cin>>n>>k;
	fore(i,0,n){
		ll x;
		cin>>x; a.pb(x);
	}
	ll l=0, r=INF;
	while(l<=r){
		ll h=(l+r)/2;
		cout<<"l="<<l<<" r="<<r<<" :\n";
		if(check(h)) l=h+1;
		else r=h-1;
	}
	check(22);
	check(r);
	if(cnt!=k){
	cout<<l<<"\n";
	check(l);
	cout<<res-l*cnt<<"\n";
	cout<<res-l*cnt-l*(k-cnt)<<"\n";
	}
	else{
		cout<<r<<"\n";
		cout<<res-k*r<<"\n";
	}
	return 0;
}
/*
h=22:
agregamos en 4  2
tot=38 s=19 c=2
pasamos a:tot=62 s=2 c=1
agregamos en 0  4
tot=112 s=13 c=4
pasamos a:tot=138 s=4 c=1
cant=2
h=18:
agregamos en 5  10
tot=9 s=9 c=1
pasamos a:tot=37 s=10 c=1
agregamos en 3  8
tot=51 s=12 c=2
pasamos a:tot=77 s=8 c=1
agregamos en 0  4
tot=102 s=11 c=3
pasamos a:tot=124 s=4 c=1
cant=3
19
h=19:
agregamos en 4  2
tot=38 s=19 c=2
pasamos a:tot=59 s=2 c=1
agregamos en 0  4
tot=109 s=13 c=4
pasamos a:tot=132 s=4 c=1
cant=2
94
94

*/