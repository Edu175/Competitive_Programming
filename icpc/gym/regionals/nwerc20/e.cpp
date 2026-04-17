#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

ll C=5,R=100; // 15 is ok

int main(){
	JET
	ll n; cin>>n;
	ii a,b; cin>>a.fst>>a.snd>>b.fst>>b.snd;
	a.fst--,a.snd--,b.fst--,b.snd--;
	vv x(n),y(n);
	// vv isx(2*n+5),isy(2*n+5);
	set<ii>st={{0,0}};
	// cerooo
	
	fore(i,0,n){
		cin>>x[i]>>y[i];
		//isx[x[i]+n]=isy[y[i]+n]=1;
		st.insert({x[i],y[i]});
	}
	auto valid=[&](ll i , ll j){
		return i>=0&&i<n&&j>=0&&j<n;
	};
	auto reach=[&](ii a, ii b){
		if(a==b)return 1;
		ll dx=b.fst-a.fst,dy=b.snd-a.snd;
		fore(i,0,n){
			if(valid(a.fst+x[i],a.snd+y[i])&&
			st.count(ii({dx-x[i],dy-y[i]}))){
				// cout<<"reached with move "<<a.fst<<","<<a.snd<<" "<<a.fst+<<""<<": "
				// <<x[i]<<","<<y[i]<<": "<<dx-x[i]<<","<<dy-y[i]<<"\n";
				return 1;
			}
		}
		return 0;
	};
	if(reach(a,b)){
		cout<<"Alice wins\n";
		return 0;
	}
	
	if(n<=C){
		ii pos={-1,-1};
		fore(i,0,n)fore(j,0,n){
			ii p={i,j};
			if(!reach(b,p))pos=p;
		}
		// cout<<"can "<<i+1<<" "<<j+1<<"??\n";
		if(pos.fst==-1)cout<<"Bob wins\n";
		else cout<<"tie "<<pos.fst+1<<" "<<pos.snd+1<<"\n";
		return 0;
	}
	while(1){
		ll i=rng()%n,j=rng()%n;
		if(!reach(b,{i,j})){
			cout<<"tie "<<i+1<<" "<<j+1<<"\n";
			break;
		}
	}
	
}





/*
3
2 3
1 3
-2 1
1 1
1 0
reached with move 2: 1,0: -2,0
Alice wins




*/