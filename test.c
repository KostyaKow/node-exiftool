#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int test(char* str) {
   FILE* f = fopen("/dev/kmsg", "w");
   fprintf(f, str);
   return fclose(f);
}

char* get_data(char* dir) {
   char* command = malloc(strlen(dir) + 100);
   sprintf(command, "../Image-ExifTool-9.70/exiftool %s", dir);
   FILE* f = popen(command, "r");

   free(command);

   int pos = 0, len = 2048;
   char* buf = malloc(len);

   while (true) {
   fgets(buf, 1024, f)
   }
   
   pclose(f);
   return buf;
}

char* system_str(char* command) {
   FILE* f = popen(command, "r");
   char* buf = malloc(2048);
   while (fgets(buf, 1024, f)) ;

   pclose(f);
   return buf;
}
