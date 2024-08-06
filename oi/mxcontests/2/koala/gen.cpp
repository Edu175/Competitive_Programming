#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,mxcont=b;i<mxcont;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jfhg:v)cout<<jfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	ll n,w; cin>>n>>w;
	vector<ll>a(n);
	iota(ALL(a),1);
	cout<<"3\n"<<1100<<"\n";
	fore(h,0,11){
		fore(i,0,100){
			// shuffle(ALL(a),rng);
			cout<<n<<" "<<w<<" ";imp(a);
			auto ai=a;
			fore(i,0,n)a[i]=ai[(i+1)%n];
		}
		reverse(ALL(a));
		if(h&1)shuffle(ALL(a),rng);
	}
}