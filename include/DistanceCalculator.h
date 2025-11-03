
void getBigrams(char fileData[][200],int fileSize, char bigrams[][200][2],int bigramsPerLine[]);
float calculateDiceDistance(char bigramsA[][2],int bigramsAcount, char bigramsB[][2], int bigramsBCount);
void fileDistanceCalculation(int file1Size, int file2Size, float distanceMatrix[file1Size][file2Size],char file1Data[][200], char file2Data[][200] );
