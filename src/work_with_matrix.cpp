#include "../include/Matrix.h"

int main() {
  Matrix a(3, 3);
  cin >> a;
  cout << a;
  unsigned w = a.Matrix_GetHeight();
  cout << w << endl;
  unsigned h = a.Matrix_GetWidth();
  cout << h << endl;
  Matrix d(a);
  cout << d;
  Matrix e;
  e = a;
  cout << e;

  a[0][0] = 10;
  cout << a;
  a[1][1] = 20;
  a[0][0] = 11;
  cout << a;
  return 0;
}
