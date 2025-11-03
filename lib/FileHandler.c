#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileSize(char *fileName) {

  FILE *filePtr = fopen(fileName, "r");

  if (!filePtr) {
    printf("Failure Opening File %s\n", fileName);
  }

  int cr = getc(filePtr);
  int fileNumberOfLines = 0;
  while (cr != EOF) {
    if (cr == '\n') {
      fileNumberOfLines++;
    }

    cr = getc(filePtr);
  }
  fclose(filePtr);
  return fileNumberOfLines;
}
void handleFileLoading(char *fileName, char fileData[][200],
                       int fileNumberOfLines) {
  FILE *filePtr = fopen(fileName, "r");
  int curr_line = 0;

  while (curr_line < fileNumberOfLines) {
    fgets(fileData[curr_line], 200, filePtr);
    curr_line++;
  }
  fclose(filePtr);
  printf("%s Succefully Loaded\n",fileName);
}
