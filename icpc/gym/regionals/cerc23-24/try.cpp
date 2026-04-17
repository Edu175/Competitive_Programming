#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto kgjgbrb:v)cout<<kgjgbrb<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	vector<ii>a={{1,2},{3,4}};
	for(auto [x,y]:a)cout<<x<<","<<y<<" ";;cout<<"\n";
	for(auto &[x,y]:a)x++,y++;
	for(auto [x,y]:a)cout<<x<<","<<y<<" ";;cout<<"\n";
	
	return 0;
}