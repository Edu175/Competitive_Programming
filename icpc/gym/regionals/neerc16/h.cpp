#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e6,Lb=-(1<<15),Rb=1<<15;

int main(){
    JET
    #ifdef ONLINE_JUDGE
    freopen("hard.in","r",stdin);     freopen("hard.out","w",stdout);
    #endif
	// cout<<"bounds "<<Lb<<" "<<Rb<<"\n";
	vector<ii> rs;
	string s;
	string cmp;
	vv nums;
	auto process=[&](){
		// cout<<"process ";
		// for(auto i:nums)cout<<i<<" ";
		ll l=-INF,r=INF;
		if(SZ(nums)==2)l=nums[0],r=nums[1];
		else {
			if(cmp==">=")l=nums[0];
			else r=nums[0];
		}
		// cout<<": "<<l<<" "<<r<<"\n";
		if(l<=r)rs.pb({l,-r});
		cmp.clear();
		nums.clear();
	};
	while(cin>>s){
		if(s[0]=='>'||s[0]=='<')cmp=s;
		else if(s[0]=='&'||s[0]=='x');
		else if(s[0]=='|'){
			process();
		}
		else nums.pb(stoll(s));
	}
	process();
	if(!SZ(rs)){
		cout<<"false\n";
		return 0;
	}
	sort(ALL(rs));
	// ll R=-2*INF;
	vector<ii>a;
	for(auto [l,r]:rs){
		ll R=SZ(a)?a.back().snd:-2*INF;
		r=-r+1;
		if(r<=R)continue;
		if(l<=R)a.back().snd=r;
		else a.pb({l,r});
	}
	
	if(SZ(a)==1&&a[0].fst<=Lb&&Rb<=a[0].snd){
		cout<<"true\n";
		return 0;
	}
	
	fore(i,0,SZ(a)){
		auto [l,r]=a[i];
		// r--; // saco
		ll did=0;
		if(l>Lb){ // aca es if l > Lb
			cout<<"x >= "<<l;
			did=1;
		}
		if(r<Rb){
			if(did)cout<<" && ";
			cout<<"x <= "<<r-1;
			did=1;
		}
		assert(did);
		if(i!=SZ(a)-1){
			cout<<" ||\n";
		}
	}
	cout<<"\n";
    return 0;
}