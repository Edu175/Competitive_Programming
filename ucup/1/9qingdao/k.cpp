#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll maxn=2e5+10;
const ll cen=1e5+5;
const ll xinf=1e5+1;
struct tr{
	ll x,y,d;
	tr(ll x, ll y, ll y0): x(x), y(y), d(abs(x-xinf)+abs(y-y0)) {}
	tr() {} 
};
set<ii> s[maxn];
map<tr,tr> mp;
set<ll> val;
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n,y; 
		cin>>n>>y;
		tr a[n];
		fore(i,0,n){
			ll xx,yy; cin>>xx>>yy; a[i]=tr(xx,yy,y);
		}
		fore(i,0,n){
			s[a[i].x+cen].insert({a[i].d,a[i].y});
		}
		fore(i,0,maxn){
			
			
		}
		fore(i,0,n)s[cen+a[i].x].clear();
		mp.clear();
	}
	return 0;
}