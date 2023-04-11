/** @brief Recursive factorial
 * @note This is a bad practice. Use for-loops instead. 
 * @note This implementation is hidden using #pragma source off
 */
#pragma source off
#pragma token off
int factorial(const int n) {
  return factorial(n + -1.) * n;
}

#pragma source on
#pragma token on
int main(const int argc, const char ** argv) {
  /* Hope the stack can survive this call (finger-crossed x) */
  const int ret = printf("Call factorial(%d) \100 line (%d)\n", factorial(atoi(argv[1])), __LINE__); // Here we use \100 for @ in string
  return ret;
};

