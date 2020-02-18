#include <stdio.h>
#include <omp.h>

int main(void)
{
  #pragma omp parallel num_threads(8)
  {
    printf("Hello world, by thread %d !\n", omp_get_thread_num());
  }
  return 0;
}
