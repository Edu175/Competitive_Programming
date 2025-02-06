#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

random_device rd;
mt19937 rng(rd());

int main(){
	ll MAXN=2e5;
	cout<<MAXN<<"\n";
	fore(i,0,MAXN){
		cout<<i<<" ";
	}
	cout<<"\n";
	fore(i,0,MAXN){
		ll d=rng()%MAXN;
		d++;
		cout<<d<<" ";
	}
	cout<<"\n";
	return 0;
}