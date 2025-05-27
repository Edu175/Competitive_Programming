#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;



ll n;

vector<array<ll,4>>ans;

// (-(n-1),-(n-1))
// (-1,0) (0,-1)
// void pone()
void swapea(){
	fore(i,0,2)swap(ans.back()[i],ans.back()[i+2]);
}
void solve(ll x, ll y, ll w=0){
	// cout<<"solve "<<x<<","<<y<<" "<<w<<endl;
	assert(x>=0&&y>=0);
	// if(x==0&&y==0)return;
	if(x<n&&y<n){
		// cout<<"cerca\n";
		ll sw=0;
		if(x<y)sw=1,w^=1,swap(x,y);
		if(!w)ans.pb({0,y-(n-1),n-1,y});
		else ans.pb({x,n-1,x-(n-1),0});
		if(sw){
			swapea();
			fore(i,0,2)swap(ans.back()[2*i],ans.back()[2*i+1]);	
		}
		return;
	}
	x-=n-1,y-=n-1;
	// cout<<"normal "<<x<<" "<<y<<"\n";
	// ll _x=x,_y=y;
	bool dir=0;
	assert(!(x<0&&y<0));
	assert(!(x==0&&y==0));
	ll _x=x,_y=y;
	if(y<0)dir=0,y=0;
	if(x<0)dir=1,x=0;
	assert(!(x==0&&y==0));
	
	//dado dir, poner
	ans.pb({_x,_y,_x+n-1,_y+n-1});
	if(dir)swapea();
	
	// ll w=0;
	if(x>y)x--,w=1;
	else y--,w=0;
	// cout<<"normal "<<x<<" "<<y<<"\n";
	solve(x,y,w);
}

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y>>n;
		ans.clear();
		solve(abs(x),abs(y));
		cout<<SZ(ans)<<"\n";
		for(auto [x0,y0,x1,y1]:ans){
			if(x<0)x0=-x0,x1=-x1;
			if(y<0)y0=-y0,y1=-y1;
			cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<"\n";
		}
	}
    return 0;
}