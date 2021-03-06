// Copyright (c) 2012-2013
// Akira Takahashi, Toshihiko Ando, Kohsuke Yuasa,
// Yusuke Ichinohe, Masaya Kusuda, wraith.
// Released under the CC0 1.0 Universal license.
#include <iostream>
#include <locale>

using namespace std;

int main() {
  locale currentLoc("");
  wcin.imbue(currentLoc);
  wcout.imbue(currentLoc);

  wcout << L"数値を入力してください" << endl;
  int i;
  wcin >> i;
  if (wcin) {
    wcout << i << L"が入力されました。" << endl;
  }
  else {
    wcout << L"数値が入力されませんでした" << endl;
  }
}
