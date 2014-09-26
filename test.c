#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//512 KB at a time
#define BUF_READ_SIZE 1024 * 512

int test(char* str) {
   FILE* f = fopen("/dev/kmsg", "w");
   fprintf(f, str);
   return fclose(f);
}

//like system(), but returns string instead of sending result to output
char* system_str(char* command) {
   FILE* f = popen(command, "r");
   int pos = 0, len = BUF_READ_SIZE;
   char* buf = NULL; //be careful with this loop

   while (!feof(f)) {
      if (pos + BUF_READ_SIZE >= len) {
         len *= 2;
         buf = realloc(buf, len);
      }
      int n_read = fread(buf + pos, 1, BUF_READ_SIZE, f); //TODO check with ferror()
      pos += n_read;
      if (!n_read)
         break;
   }
   buf = realloc(buf, pos + 1);
   buf[pos] = '\0';

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

