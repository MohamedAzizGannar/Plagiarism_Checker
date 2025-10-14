
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <FileHandler.h>
#include <Preprocessor.h>
#include <DistanceCalculator.h>
int main(int argc, char** argv){
    char* file1Name = argv[1];
    char* file2Name = argv[2];
    char keywordsName[] = "keyWordC.txt"; 

    int file1Size = getFileSize(file1Name);
    int file2Size = getFileSize(file2Name);
    int keywordsSize = getFileSize(keywordsName);


    char file1Data[file1Size][100];
    char file2Data[file2Size][100];
    char keywordsData[keywordsSize][100];

    handleFileLoading(file1Name,file1Data,file1Size);
    handleFileLoading(file2Name,file2Data,file2Size);
    handleFileLoading(keywordsName,keywordsData,keywordsSize);
    printf("Files Loaded\n");

    PreprocessFile(file2Data,&file2Size,keywordsData,keywordsSize);
    PreprocessFile(file1Data,&file1Size,keywordsData,keywordsSize);
    printf("Preprocess Complete\n");

    char bigrams1[file1Size][100][2]; 
    int bigrams1PerLine[file1Size];
    getBigrams(file1Data,file1Size,bigrams1,bigrams1PerLine);
 
    char bigrams2[file2Size][100][2]; 
    int bigrams2PerLine[file2Size];
    getBigrams(file2Data,file2Size,bigrams2,bigrams2PerLine);
    printf("Bigram Loading Complete\n"); 

    return 0 ;
}

