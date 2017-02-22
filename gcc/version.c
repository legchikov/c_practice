int main() {

  printf("gcc version: %d.%d.%d\n",__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__);
  return 0;
}

// $gcc -dM -E - < /dev/null
// $gcc -v
