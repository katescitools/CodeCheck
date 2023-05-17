int a; /* UNDCC_Violation */
int b = 0; /* UNDCC_Valid */

int main() {
  a = 1;
  b = 1;
  char c; /* UNDCC_Violation */
  char d = 'a'; /* UNDCC_Valid */
  c = 'b';
  d = 'b';
}
