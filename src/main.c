
#include <DistanceCalculator.h>
#include <FileHandler.h>
#include <Preprocessor.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  (void)argc;

  char *file1Name = argv[1];
  char *file2Name = argv[2];
  char keywordsName[] = "keyWordC.txt";

  int file1Size = getFileSize(file1Name);
  int file2Size = getFileSize(file2Name);
  int keywordsSize = getFileSize(keywordsName);

  char file1Data[file1Size][200];
  char file2Data[file2Size][200];
  char keywordsData[keywordsSize][200];

  handleFileLoading(file1Name, file1Data, file1Size);
  handleFileLoading(file2Name, file2Data, file2Size);
  handleFileLoading(keywordsName, keywordsData, keywordsSize);

  removeWhiteSpace(keywordsData, &keywordsSize);

  PreprocessFile(file1Data, &file1Size, keywordsData, keywordsSize);
  PreprocessFile(file2Data, &file2Size, keywordsData, keywordsSize);

  char bigrams1[file1Size][200][2];
  int bigrams1PerLine[file1Size];

  getBigrams(file1Data, file1Size, bigrams1, bigrams1PerLine);

  char bigrams2[file2Size][200][2];
  int bigrams2PerLine[file2Size];

  getBigrams(file2Data, file2Size, bigrams2, bigrams2PerLine);

  printf("Bigram Loading Complete\n");

  float diceDistanceMatrix[file1Size][file2Size];
  fileDistanceCalculation(file1Size, file2Size, diceDistanceMatrix, file1Data,
                          file2Data);

  printf("Distance Matrix Calculated\n");

  for (int i = 0; i < file1Size; i++) {
    for (int j = 0; j < file2Size; j++) {
      printf("%f ", diceDistanceMatrix[i][j]);
    }
    printf("\n");
  }

  FILE *pgmIMG;

  pgmIMG = fopen("pgmIMG.pgm", "wb");
  fprintf(pgmIMG, "P2\n");
  fprintf(pgmIMG, "%d %d\n", file1Size, file2Size);
  fprintf(pgmIMG, "255\n");

  float temp;
  for (int i = 0; i < file1Size; i++) {
    for (int j = 0; j < file2Size; j++) {
      temp = diceDistanceMatrix[i][j];
      fprintf(pgmIMG, "%d ", (int)(temp * 255));
    }
    fprintf(pgmIMG, "\n");
  }
  fclose(pgmIMG);
  return 0;
}
