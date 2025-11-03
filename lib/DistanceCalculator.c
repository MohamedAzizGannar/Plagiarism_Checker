#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
void getBigrams(char fileData[][200],int fileSize, char bigrams[][200][2],int bigramsPerLine[]){
    for(int i = 0; i < fileSize; i++){
        int bigramsIndex = 0;  
        int lineSize = strlen(fileData[i]);
        for(int j = 0; j < lineSize - 1; j++){
               bigrams[i][bigramsIndex][0] = fileData[i][j];
               bigrams[i][bigramsIndex][1] = fileData[i][j+1];
               bigramsIndex++;
        }
        bigramsPerLine[i] = bigramsIndex;
    }
}
float calculateDiceDistance(char bigramsA[][2],int bigramsAcount, char bigramsB[][2], int bigramsBCount){
    int min = (bigramsAcount < bigramsBCount) ? bigramsAcount : bigramsBCount;
    int overlapCount = 0;
    for(int i = 0;i < min; i++){
        if(bigramsA[i][0] == bigramsB[i][0] && bigramsA[i][1] == bigramsB[i][1]){
            overlapCount ++;
        }
    }
    float diceCoefficient = (2. * overlapCount) / (bigramsAcount + bigramsBCount);
    return 1 - diceCoefficient;
}
void fileDistanceCalculation(int file1Size, int file2Size, float distanceMatrix[file1Size][file2Size],char file1Data[][200], char file2Data[][200] ){
    char bigrams1[file1Size][200][2];
    char bigrams2[file2Size][200][2];

    int bigramsPerLine1[file1Size];
    int bigramsPerLine2[file2Size];

    getBigrams(file1Data,file1Size,bigrams1,bigramsPerLine1);
    getBigrams(file2Data,file2Size,bigrams2,bigramsPerLine2);

    for(int i = 0; i < file1Size; i++){
        for(int j = 0; j < file2Size; j++){
            float currentDistance = calculateDiceDistance(bigrams1[i],bigramsPerLine1[i],bigrams2[j],bigramsPerLine2[j]);
            distanceMatrix[i][j] = currentDistance;
        }
    }
}

