#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeComments(char fileData[][200], int *fileSize) {
  int i = 0;

  while (i < *fileSize) {
    char *commentPos = strstr(fileData[i], "//");
    if (commentPos != NULL) {
      *commentPos = '\0';
    }
    i++;
  }
}

void removeWhiteSpace(char fileData[][200], int *fileSize) {

  for (int i = 0; i < *fileSize; i++) {
    int nonSpaceCount = 0;

    for (int j = 0; fileData[i][j] != '\0'; j++) {
      if (!isspace(fileData[i][j])) {
        fileData[i][nonSpaceCount] = fileData[i][j];
        nonSpaceCount++;
      }
    }
    fileData[i][nonSpaceCount] = '\0';
  }
}

void removeWords(char fileData[][200], int *fileSize, char keywords[][200],
                 int keywordsSize) {

  for (int i = 0; i < *fileSize; i++) {
    int wordCount = 0;
    int first = 1;
    for (int j = 0; fileData[i][j] != '\0'; j++) {
      if (!isalnum(fileData[i][j])) {
        fileData[i][wordCount] = fileData[i][j];
        wordCount++;
        first = 1;
      } else if (first == 1) {
        char currWord[50] = "";
        int start = j;
        while (isalnum(fileData[i][start]) && start < 200) {
          currWord[start - j] = fileData[i][start];
          start++;
        }
        currWord[start-j] = '\0';
        int isKeyword = 0;
        for (int k = 0; k < keywordsSize; k++) {
          if (strcmp(currWord, keywords[k]) == 0)
            isKeyword = 1;
        }
        if (isKeyword == 1) {
          fileData[i][wordCount] = 'm';
        } else {
          fileData[i][wordCount] = 'w';
        }
        first = 0;
        wordCount++;
      }
    }
    fileData[i][wordCount] = '\0';
  }
}
void removeStrings(char fileData[][200], int *fileSize) {
  for (int i = 0; i < *fileSize; i++) {
    int nonString = 0;
    for (int j = 0; fileData[i][j] != '\0'; j++) {
      if (fileData[i][j] == '\"') {
        fileData[i][nonString] = '\"';
        nonString++;
        int start = j + 1;
        while (fileData[i][start] != '\"' && start < 100) {
          start++;
        }
        if (fileData[i][start] == '\"') {
          fileData[i][nonString] = '\"';
          j = start;
          nonString++;
        } else {
          j = start - 1;
        }
      } else if (fileData[i][j] == '\'') {

        fileData[i][nonString] = '\'';
        nonString++;
        int start = j + 1;
        while (fileData[i][start] != '\'' && start < 200) {
          start++;
        }
        if (fileData[i][start] == '\'') {
          fileData[i][nonString] = '\'';
          j = start;
          nonString++;
        } else {
          j = start - 1;
        }
      } else {
        fileData[i][nonString] = fileData[i][j];
        nonString++;
      }
    }
    fileData[i][nonString] = '\0';
  }
}
void resolveEmptyLines(char fileData[][200], int *fileSize) {
  int nonEmptyLines = 0;
  for (int i = 0; i < *fileSize; i++) {
    if (fileData[i][0] != '\0') {
      if (i != nonEmptyLines) {
        strcpy(fileData[nonEmptyLines], fileData[i]);
      }
      nonEmptyLines++;
    }
  }
  *fileSize = nonEmptyLines;
}
void resolveOneCharLines(char fileData[][200], int *fileSize) {
  int nonOneCharLines = 0;
  for (int i = 0; i < *fileSize; i++) {
    int len = strlen(fileData[i]);
    if (len == 1) {
      int previous = nonOneCharLines - 1;
      if (previous >= 0) {

        int lenPrevious = strlen(fileData[previous]);
        if (lenPrevious < 199) {
          fileData[previous][lenPrevious] = fileData[i][0];
          fileData[previous][lenPrevious + 1] = '\0';
        } else {
          if (i != nonOneCharLines) {
            strcpy(fileData[nonOneCharLines], fileData[i]);
          }
          nonOneCharLines++;
        }
      } else {
        if (nonOneCharLines != i) {
          strcpy(fileData[nonOneCharLines], fileData[i]);
        }
        nonOneCharLines++;
      }
    } else {
      if (nonOneCharLines != i) {
        strcpy(fileData[nonOneCharLines], fileData[i]);
      }
      nonOneCharLines++;
    }
  }
  *fileSize = nonOneCharLines;
}
void PreprocessFile(char fileData[][200], int *fileSize, char keywords[][200],
                    int keywordsSize) {
  removeComments(fileData, fileSize);
  printf("Comments Succesfully Removed\n");
  removeWords(fileData, fileSize, keywords, keywordsSize);
  printf("Words Succesfully Removed\n");
  removeWhiteSpace(fileData, fileSize);
  printf("WhiteSpace Succesfully Removed\n");
  removeStrings(fileData, fileSize);
  printf("Strings Succesfully Removed\n");
  resolveEmptyLines(fileData, fileSize);
  resolveOneCharLines(fileData, fileSize);
  printf("EmptyLines Succesfully Removed\n");
}
