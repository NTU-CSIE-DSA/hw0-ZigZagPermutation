#include "testlib.h"

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, 10);
  inf.readEoln();
  for(int i = 0; i < n; i++) {
    inf.readInt(-1000000000, 1000000000);
    if(i == n - 1) inf.readEoln();
    else inf.readSpace();
  }
  inf.readEof();
}
