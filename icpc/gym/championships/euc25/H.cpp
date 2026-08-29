#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;


void solve(ll x, ll y, vector<ii> &r, vv &d, vv& vis){
	ll n = SZ(r);
	// cout<<"pre solve\n";
	// for(auto [i,j] : r) cout<<i<<" "<<j<<"\n";
	fore(k,0,n){
		auto &[i,j] = r[k];
		if(vis[k]) continue;
		if(!x){
			j = d[k];
			y-=j;
		}
		else{
			i = d[k];
			x-=i;
			if(x < 0){
				j = -x;
				i -= j;
				x = 0;
				y -=j;
			}
		}
	}
	assert(!x && !y);
	return;
}

void responder(vector<ii> &r, bool b){
	cout<<"YES\n";
	ll x = 0, y = 0;
	cout<<x<<" "<<y<<"\n";
	for(auto [i,j] : r){
		if(b) swap(i,j);
		x+=i, y+=j;
		cout<<x<<" "<<y<<"\n";
	}
}

int main(){
	JET
	ll n; cin>>n;
	ll a,b; cin>>a>>b;
	ll sum = 0;
	vv d(n-1);
	fore(i,0,n-1){
		cin>>d[i];
		sum+=d[i];
	}
	if(sum < a+b || ((sum - (a+b))&1)){
		cout<<"NO\n";
		return 0;
	}
	ll k = (sum - (a+b))/2;
	bool change = 0;
	if(a < b) swap(a,b), change = 1;
	vector<ii> res(n-1,{0,0});
	vv vis(n-1,0);
	
	
	// veo si existe el especial y lo marco
	ll esp = -1;
	fore(i,0,n-1) if(k<=d[i] && d[i]<=a+k) esp = i;
	if(esp >= 0){
		res[esp] = {d[esp]-k,-k};
		vis[esp] = 1;
		solve(a - (d[esp]-k),b+k,res,d,vis);
		responder(res,change);
		return 0;
	}
	
	
	// veamos los menores a k y encontremos lo piola
	ll izq = 0;
	fore(i,0,n-1)if(d[i] < k){
		if(izq+d[i] >= k){
			res[i].snd = -(k - izq);
			res[i].fst = d[i] + res[i].snd;
			vis[i] = 1;
			solve(a+izq - res[i].fst,b-res[i].snd,res,d,vis);
			responder(res,change);
			return 0;
		}
		res[i].fst = -d[i];
		vis[i] = 1;
		izq += d[i];
	}
	cout<<"NO\n";
	return 0;
}