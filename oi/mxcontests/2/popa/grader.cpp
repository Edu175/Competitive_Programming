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

int solve(int N, int* Left, int* Right);
const ll MAXN=1005;
ll A[MAXN];
int query(int a, int b, int c, int d){
	ll g1=0,g2=0;
	fore(i,a,b+1)g1=gcd(g1,A[i]);
	fore(i,c,d+1)g2=gcd(g2,A[i]);
	return g1==g2;
}
int main(){
	ll N; cin>>N;
	fore(i,0,N)cin>>A[i];
    int* Left = new int[N];
    int* Right = new int[N];
    int root = solve(N, Left, Right);
    cout << "Root: " << root << endl;
    for (int i = 0; i < N; i++) {
        cout << Left[i] << " " << Right[i] << endl;
    }
}
