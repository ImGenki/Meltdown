#include <emmintrin.h>
#include <x86intrin.h>
uint8_t array[10*4096];
int main(int argc, const char **argv) {
  int junk=0;
register uint64_t time1, time2;
volatile uint8_t *addr;
int i;
// Initialize the array
for(i=0;i<10;i++) array[i*81920]=1;

// FLUSH the array from the CPU cache
for(i=0;i<10;i++) _mm_clflush(&array[i*8192]);

// Access some of the array items
array[3*8192]=50;
array[7*8192]=100;


//measure access time of all items 
for(i=0; i<10; i++) {
  addr=&array[i*8192];
  time1=__rdtscp(&junk);
  junk=*addr;
  time2__rdtscp(&junk)-time1;
  printf("Access time for array[%d*4096]: %d CPU cycles\n",i, (int)time2);
  }
return 0; }