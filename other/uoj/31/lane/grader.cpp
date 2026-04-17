#include <iostream>
#include "lane.h"

namespace {
  constexpr int MAX_N = (int)1E5, MAX_T = (int)1E6, MAX_SUM_N = (int)1E7;
  constexpr int QUERY_LIMIT = (int)2E6;
  constexpr double EPS = 1E-9;
  int subtask, n, a[MAX_N], cnt_operation, cnt_cost, pos, current_case, full_score;
  double max_rate;
  void print_testcase() {
    if (current_case) std::cout << " (testcase " << current_case << ")";
    std::cout << std::endl;
  }
  void report_result(double score, const std::string& msg) {
    if (score < EPS) std::cout << "Wrong answer" << std::endl;
    else if (score > full_score - EPS) std::cout << "Accepted" << std::endl;
    else std::cout << "Partially correct (" + std::to_string(score) + " points)" << std::endl;
    std::cout << msg;
    print_testcase();
    exit(score > full_score - EPS ? 0 : 1);
  }
  void ensure(bool condition, int t) {
    if (!condition) {
      std::cout << "Invalid Input [" << t << "]" << std::endl;
      print_testcase();
      exit(1);
    }
  }
  void inc_operations() {
    cnt_operation++;
    if (cnt_operation > (subtask == 1 ? QUERY_LIMIT : 20 * n)) report_result(0, "Too many operations");
  }
  double func(int subtask, double x) {
    if (subtask == 2) {
      constexpr double FULL_LIMIT = 7.83;
      if (x <= FULL_LIMIT + EPS) return full_score;
      else if (x > 15) return 0;
      else return (15 - x) / (15 - FULL_LIMIT) * full_score;
    }
    else {
      constexpr double FULL_LIMIT = 5.35;
      if (x <= FULL_LIMIT + EPS) return full_score;
      else if (x > 8) return 0;
      else return (8 - x) / (8 - FULL_LIMIT) * full_score;
    }
  }
}

void anticlockwise() {
  #ifdef DEBUG
  std::cerr << "anticlockwise()" << std::endl;
  #endif
  inc_operations(), cnt_cost++;
  if (!pos) pos = n;
  pos--;
}
void clockwise() {
  #ifdef DEBUG
  std::cerr << "clockwise()" << std::endl;
  #endif
  inc_operations(), cnt_cost++;
  pos++;
  if (pos == n) pos = 0;
}
bool ask() {
  #ifdef DEBUG
  std::cerr << "ask()" << std::endl;
  #endif
  inc_operations(), cnt_cost++;
  return a[pos];
}
void flip() {
  #ifdef DEBUG
  std::cerr << "flip()" << std::endl;
  #endif
  inc_operations();
  a[pos] ^= 1;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T, sum_n = 0;
  std::cin >> subtask >> T;
  ensure(1 <= subtask && subtask <= 3, 1);
  ensure(1 <= T && T <= MAX_T, 2);
  full_score = subtask == 1 ? 3 : subtask == 2 ? 40 : 57;
  for (int c = 1; c <= T; c++) {
    std::string str;
    current_case = c;
    std::cin >> n >> str;
    ensure(1 <= n && n <= MAX_N, 3);
    sum_n += n, ensure(sum_n <= MAX_SUM_N, 4);
    ensure((int)str.size() == n, 5);
    for (int i = 0; i < n; i++) a[i] = str[i] - '0', ensure(a[i] == 0 || a[i] == 1, 6);
    #ifdef DEBUG
    std::cerr << "Testing n = " << n << ", a = [";
    for (int i = 0; i < n; i++) std::cerr << a[i] << (i == n - 1 ? "]\n" : ", ");
    #endif
    cnt_operation = cnt_cost = pos = 0;
    int ans = solve(subtask);
    if (ans != n) report_result(0, "Participant's answer is not correct");
    double rate = 1.0 * cnt_cost / n;
    #ifdef DEBUG
    std::cerr << "Used " << cnt_operation << " operations and cost " << cnt_cost 
              << " (rate = " << rate << ", testcase " << c << ")" << std::endl;
    #endif
    if (n <= 2'000 && subtask == 3) rate /= 2;
    max_rate = std::max(max_rate, rate);
  }
  current_case = 0;
  if (subtask == 1) report_result(full_score, "Correct answers");
  else report_result(func(subtask, max_rate), "Correct answers (max_rate = " + std::to_string(max_rate) + ")");
  return 0;
}
