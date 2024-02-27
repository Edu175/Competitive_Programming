#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef uint64_t th; //hash type
typedef pair<ll,ll> ii;

static uint64_t rnd(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

int main(){FIN;
	string s; cin>>s;
	th sum=0;
	vector<bool>d(26);
	fore(i,0,SZ(s))if(!d[s[i]-'a'])sum+=rnd(s[i]),d[s[i]-'a']=1;
	th h=0;
	unordered_map<th,int>mp;
	mp[0]=1;
	ll res=0;
	fore(i,0,SZ(s)){
		if(s[i]==s[0])h+=-sum+rnd(s[i]);
		else h+=rnd(s[i]);
		// cout<<i<<" "<<h<<"\n";
		res+=mp[h]++;
	}
	cout<<res<<"\n";
	return 0;
}

