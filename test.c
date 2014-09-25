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

   fseek(f, 0, SEEK_END);
   long fsize = ftell(f);
   fseek(f, 0, SEEK_SET);

   char* buf = malloc(fsize + 1);
    fread(buf, fsize, 1, f);

   pclose(f);
   buf[fsize] = 0;
   return buf;
}

char* get_data(char* dir) {
   char* command = malloc(strlen(dir) + 50); //50 is about the length of string below
   sprintf(command, "../Image-ExifTool-9.70/exiftool %s", dir);
   
   char* result = system_str(command);

   free(command);
   return result;
}

