#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b; i<ioi; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto dfg:v)cout<<dfg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<int> r;

void give_initial_chart(int H, int W, std::vector<int> R, std::vector<int> C) {
  r = R;
  
}

int swap_seats(int a, int b) {
  return r[a];
}
