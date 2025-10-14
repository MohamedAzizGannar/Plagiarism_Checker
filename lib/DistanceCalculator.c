#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
void getBigrams(char fileData[][100],int fileSize, char bigrams[][100][2],int bigramsPerLine[]){
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
    printf("Overlap = %d\n",overlapCount);
    float diceCoefficient = (2. * overlapCount) / (bigramsAcount + bigramsBCount);
    printf("biCount = %d\n",bigramsAcount + bigramsBCount);
    return 1 - diceCoefficient;
}
