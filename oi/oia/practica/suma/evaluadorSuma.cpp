#include <iostream>
#include <vector>

using namespace std;

long long suma(vector<int> v);

int main()
{
    int n; cin >> n;
    vector<int> numbers(n);
    for (int i=0;i<n;i++)
        cin >> numbers[i];
    long long ret = suma(numbers);
    cout << ret << endl;
    return 0;
}
