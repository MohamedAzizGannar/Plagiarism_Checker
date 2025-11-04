#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

void getBigrams(char fileData[][200], int fileSize, char bigrams[][200][2],
                int bigramsPerLine[]) {
  for (int i = 0; i < fileSize; i++) {
    int bigramsIndex = 0;
    int lineSize = strlen(fileData[i]);
    for (int j = 0; j < lineSize - 1; j++) {
      bigrams[i][bigramsIndex][0] = fileData[i][j];
      bigrams[i][bigramsIndex][1] = fileData[i][j + 1];
      bigramsIndex++;
    }
    bigramsPerLine[i] = bigramsIndex;
  }
}
float calculateDiceDistance(char bigramsA[][2], int bigramsAcount,
                            char bigramsB[][2], int bigramsBCount) {
  int min = (bigramsAcount < bigramsBCount) ? bigramsAcount : bigramsBCount;
  int overlapCount = 0;
  for (int i = 0; i < min; i++) {
    if (bigramsA[i][0] == bigramsB[i][0] && bigramsA[i][1] == bigramsB[i][1]) {
      overlapCount++;
    }
  }
  float diceCoefficient = (2. * overlapCount) / (bigramsAcount + bigramsBCount);
  return 1 - diceCoefficient;
}
void fileDistanceCalculation(int file1Size, int file2Size,
                             float distanceMatrix[file1Size][file2Size],
                             char file1Data[][200], char file2Data[][200]) {
  char bigrams1[file1Size][200][2];
  char bigrams2[file2Size][200][2];

  int bigramsPerLine1[file1Size];
  int bigramsPerLine2[file2Size];

  getBigrams(file1Data, file1Size, bigrams1, bigramsPerLine1);
  getBigrams(file2Data, file2Size, bigrams2, bigramsPerLine2);

  for (int i = 0; i < file1Size; i++) {
    for (int j = 0; j < file2Size; j++) {
      float currentDistance = calculateDiceDistance(
          bigrams1[i], bigramsPerLine1[i], bigrams2[j], bigramsPerLine2[j]);
      distanceMatrix[i][j] = currentDistance;
    }
  }
}
char getStringHead(char str[], int strSize) {
  if (strSize == 0) {
    printf("Error: String is Empty : %d\n", errno);
    return '\0';
  }
  return str[0];
}
void getStringTail(char s1[], int s1Size, char *container) {
  char s1Tail[s1Size - 1];
  for (int i = 0; i < s1Size - 1; i++) {
    s1Tail[i] = s1[i];
  }
  strcpy(container, s1Tail);
}
float calculateLevenshteinDistance(char s1[], char s2[], int s1Size,
                                   int s2Size) {
  if (s1[0] == '\0')
    return s2Size;
  else if (s2[0] == '\0')
    return s1Size;
  else if (getStringHead(s1, s1Size) == getStringHead(s2, s2Size)) {
    char *s1Tail = (char *)malloc((s1Size - 1) * sizeof(char));
    char *s2Tail = (char *)malloc((s2Size - 1) * sizeof(char));

    getStringTail(s1, s1Size, s1Tail);
    getStringTail(s2, s2Size, s2Tail);

    calculateLevenshteinDistance(s1Tail, s2Tail, s1Size - 1, s2Size - 2);
  }
  else{

    char *s1Tail = (char *)malloc((s1Size - 1) * sizeof(char));
    char *s2Tail = (char *)malloc((s2Size - 1) * sizeof(char));
    getStringTail(s1, s1Size, s1Tail);
    getStringTail(s2, s2Size, s2Tail);
    
    float lev_tailA_B = calculateLevenshteinDistance(s1Tail,s2,s1Size - 1,s2Size);
    float lev_A_tailB = calculateLevenshteinDistance(s1,s2Tail,s1Size,s2Size - 1);
    float lev_tailA_tailB = calculateLevenshteinDistance(s1Tail,s2Tail,s1Size - 1,s2Size - 1);
    return 1 + MIN(lev_tailA_tailB, MIN(lev_A_tailB,lev_tailA_B));
  }
}
