#include "choreography.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll a[MAXN];
ll n,t=0;

vector<vector<ll>> izq(2);
vector<vector<ii>> der(2);

void init(int N, std::vector<int> P) {
	n=N;
	fore(i,0,n)a[i]=P[i];
    return;
} 
//USE &1 NOT %2
void move_right(int k) {
	if(k&1)swap(izq[t][0],izq[t][1]);
	izq[t][0]=(izq[t][0]-k+n)%n;
	izq[t][1]=(izq[t][1]-k+n)%n;
    return;
}

void move_left(int k) {
	move_right(-k);
    return;
}

void swap_places() {
    return;
}

void move_around() {
    return;
}

int get_position(int D){
    return 0;
}
