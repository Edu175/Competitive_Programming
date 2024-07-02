#include <bits/stdc++.h>
using namespace std;
#include <tr2/dynamic_bitset>
using namespace tr2;

int32_t main() {
    dynamic_bitset<> test(91);
    test[50] = true;
	auto shifted=test;
    cout << shifted << "\n";
	shifted<<=65;
	cout<<shifted<<"\n";
    
	cout << (test << 78) << "\n";
    /*cout << "\n";
    
    bitset<91> test2;
    test2[50] = true;
    cout << test2 << "\n";
    cout << (test2 << 78) << "\n";*/
    return 0;
}

