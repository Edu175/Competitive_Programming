#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

/*
*  rnd.next(4) - Random int bw 0-3
*  rnd.next(4, 100) - Random int bw 4-100
*  rnd.next(10.0) - Random real [0;10)
*  rnd.next("one|two|three") Random word out of 'one', 'two' and 'three'
*  rnd.next("[1-9][0-9]{99}") Random REGEX (100-digit number as a string)
*  rnd.wnext(4,t) wnext is a method of obtaining an uneven distribution (with a biased expectation)
*  rnd.any(container) A random element of the container container (with random access via an iterator), for example, it works for std::vector and std::string
*  shuffle
*/

int main(int argc, char* argv[])
{
  registerGen(argc, argv, 0);
  vector <int> shirt_winners = {};
  vector <int> bag_winners = {};

  for (int i = 21; i <= 200; i++) shirt_winners.push_back(i);
  for (int i = 201; i <= 1500; i++) bag_winners.push_back(i);

  shuffle(shirt_winners.begin(), shirt_winners.end());
  shuffle(bag_winners.begin(), bag_winners.end());

  // list of shirt winners
  cout << "===== Rank of SHIRT WINNERS =====\n";
  for (int i = 0; i < 30; i++) {
    cout << shirt_winners[i] << ' ';
  }
  cout << "\n";

  // list of bag winners
  cout << "===== Rank of BAG WINNERS =====\n";
  for (int i = 0; i < 100; i++) {
    cout << bag_winners[i] << ' ';
  }
  cout << "\n";
}
	
