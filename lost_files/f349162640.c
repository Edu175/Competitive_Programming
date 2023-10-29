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

vector<ll>a,p;
ll n;


void init(int N, std::vector<int> A) {
	n=N;
	a.resize(n); p.resize(n);
	fore(i,0,n)a[i]=A[i],p[a[i]]=i;
    return;
} 
//USE &1 NOT %2
void move_right(int k) {
	vector<ll>ai(n);
	fore(i,0,n)ai[i]=a[(i-k+n)%n];
	a=ai;
	fore(i,0,n)p[a[i]]=i;
}

void move_left(int k) {
	move_right(-k);
    return;
}

void swap_places() {
	fore(i,0,n){
		if(i&1)continue;
		swap(a[i],a[i+1]);
	}
	fore(i,0,n)p[a[i]]=i;
}

void move_around() {
	t^=1;
    return;
}

int get_position(int x){
	x=(x+izq[t^1][x&1])%n;
	if(!t)x=p[x];
	else x=a[x];
	x=(x+der[t][x&1].fst)%n;
    return x;
}
