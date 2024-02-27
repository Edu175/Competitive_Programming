#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
vector<ii> dir={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
bool is_prime(ll n){
	for(ll i=2;i*i<=n;i++)if(n%i==0)return 0;
	return 1;
}
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll solve(vector<vector<int>>&mat){
	ll n=SZ(mat),m=SZ(mat[0]);
	vector<vector<ll>>a(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)a[i][j]=mat[i][j];
	map<ll,ll>mp;
	fore(_i,0,n)fore(_j,0,m){
		for(auto d:dir){
			ll i=_i,j=_j;
			ll x=0;
			while(i<n&&i>=0&&j<m&&j>=0){
				x=x*10+a[i][j];
				if(x>=10&&is_prime(x))mp[x]++;
				i+=d.fst,j+=d.snd;
			}
		}
	}
	vector<ii>b;
	for(auto [i,c]:mp)b.pb({c,i});
	sort(ALL(b));
	if(!SZ(b))return -1;
	return b.back().snd;
}
int main(){
	ll n,m; cin>>n>>m;
	vector<vector<int>>a(n,vector<int>(m));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	cout<<solve(a)<<"\n";
}
class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        return solve(mat);
    }
};
