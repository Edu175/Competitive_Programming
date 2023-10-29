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

ll a[MAXN],p[MAXN];
ll n,t=0;

vector<vector<ll>> izq(2,vector<ll>(2));
vector<vector<ii>> der(2,vector<ii>(2));

void init(int N, std::vector<int> A) {
	n=N;
	fore(i,0,n)a[i]=A[i],p[a[i]]=i;
    return;
} 
//USE &1 NOT %2
void move_right(int k) {
	k=(k+n)%n;
	if(k&1)swap(izq[t][0],izq[t][1]);
	fore(i,0,2)izq[t][i]=(izq[t][i]-k+n)%n;
	
	fore(i,0,2)der[t][i].fst=(der[t][i].fst+k)%n,der[t][i].snd^=k&1;
	
    return;
}

void move_left(int k) {
	move_right(-k);
    return;
}

void swap_places() {
	swap(izq[t][0],izq[t][1]);
	izq[t][0]=(izq[t][0]+1)%n;
	izq[t][1]=(izq[t][1]-1+n)%n;
	
	fore(i,0,2){
		if(der[t][i].snd)der[t][i].fst--;
		else der[t][i].fst++;
		der[t][i].snd^=1;
	}
	
    return;
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
