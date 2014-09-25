#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int test(char* str) {
   FILE* f = fopen("/dev/kmsg", "w");
   fprintf(f, str);
   return fclose(f);
}

//like system(), but returns string instead of sending result to output
char* system_str(char* command) {
   FILE* f = popen(command, "r");
   int pos = 0, len = 2048;
   char* buf = NULL;

   while (!feof(f)) {
      pos += 1024;
      if (pos >= len || !buf) {
         len *= 2;
         buf = realloc(buf, len);
      }

      if (fgets(buf, 1024, f) == NULL)
         break;
   }

   buf = realloc(buf, pos);
   pclose(f);
   return buf;
}

char* get_data(char* dir) {
   char* command = malloc(strlen(dir) + 50); //50 is about the length of string below
   sprintf(command, "../Image-ExifTool-9.70/exiftool %s", dir);
   
   char* result = system_str(command);

   free(command);
   return result;
}

