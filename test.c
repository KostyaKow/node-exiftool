#include <stdio.h>

int test(char* str) {
   FILE* f = fopen("/dev/kmsg", "w");
   fprintf(f, str);
   return fclose(f);
}
