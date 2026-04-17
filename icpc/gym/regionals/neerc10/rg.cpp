#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

random_device rd;
mt19937 rng(rd());

int main(){
	JET
	fore(i,0,10){
		fore(j,0,10)cout<<(i+j)%10<<" ";
		cout<<"\n";
	}
	ll N; cin>>N;
	ll l=rng()%N,r=rng()%N;
	if(l>r)swap(l,r);
	cout<<l<<" "<<r<<"\n";
	return 0;
}