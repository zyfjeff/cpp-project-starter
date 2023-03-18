#include <stdio.h>

int main() {
  int* ptr_a, ptr_b;
  int array[] = { 45, 67, 89 };
  int array2[] = {1, 2, 3};
  // array = array2;
  int* p_arr = array;
  int* pp_arr = &array;
  printf("%d %d %d\n", p_arr[0], p_arr[1], p_arr[2]);
  printf("%d %d %d\n", pp_arr[0], pp_arr[1], pp_arr[2]);
  printf("address: %p, address: %p\n", p_arr, pp_arr);

  printf("%lu %lu %lu\n", sizeof(int), sizeof(array), sizeof(p_arr));
}