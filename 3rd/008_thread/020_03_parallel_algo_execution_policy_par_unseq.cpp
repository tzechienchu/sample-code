// Copyright (c) 2012-2017
// Akira Takahashi, Toshihiko Ando, Kohsuke Yuasa,
// Yusuke Ichinohe, Masaya Kusuda.
// Released under the CC0 1.0 Universal license.
#include <algorithm>
#include <atomic>
#include <execution>
#include <mutex>
#include <vector>

using namespace std;

int main() {
  vector<int> xs = { 1, 2, 3, 4, 5, 6 };

  int count = 0;
  mutex m;

  for_each(execution::par_unseq, xs.begin(), xs.end(), [&](int x) {
    // デッドロックが発生する可能性がある
    scoped_lock lock(m);
    count += 1;
  });

  atomic<int> atomic_count;
  atomic_count = 0;

  for_each(execution::par_unseq, xs.begin(), xs.end(), [&](int x) {
    // デッドロックは発生しない
    atomic_count += 1;
  });
}
