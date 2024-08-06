#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,isudgh=b;i<isudgh;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jhglkdfjg:v)cout<<jhglkdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

set<ll>st;
ll ask(ll c){
	assert(!st.count(c));
	st.insert(c);
	cout<<"? "<<c+1<<endl;
	ll ret; cin>>ret;
	return ret;
}
void bf(ll n){
	ask(0);
	ll col=0,res=1;
	for(ll i=n-1;i>0;i--){
		ll c=col+(i%2==n%2?-i:i);
		if(!ask(c)){
			res=i+1;
			break;
		}
		col=c;
	}
	cout<<"= "<<res<<endl;
	exit(0);
}
random_device rd;
mt19937 rng(rd());
int main(){FIN;
	ll n; cin>>n;
	if(n<=64)bf(n);
	ll l=1,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		ll p=-1;
		fore(i,0,n)if(!st.count(i)&&rng()&1){p=i;ask(i);break;}
		fore(i,0,n){
			auto tray=[&](ll x){
				x+=p;
				if(x>=0&&x<n&&!st.count(x))return 1;
				return 0;
			};
			vector<ll>magic={m+i,m-i}; shuffle(ALL(magic),rng);
			if(tray(magic[0])){m=magic[0];break;}
			if(tray(magic[1])){m=magic[1];break;}
		}
		if(ask(p+m))r=m-1;
		else l=m+1;
	}
	cout<<"= "<<l<<"\n";
	return 0;
}