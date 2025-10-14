
void removeWhiteSpace(char fileData[][100], int* fileSize);
void removeWords(char fileData[][100], int* fileSize, char keywords[][100], int keywordsSize);
void removeComments(char fileData[][100],int* fileSize);
void removeStrings(char fileData[][100],int* fileSize);
void resolveEmptyLines(char fileData[][100], int* fileSize);
void resolveOneCharLines(char fileData[][100], int* fileSize);
void PreprocessFile(char fileData[][100],int* fileSize, char keywords[][100], int keywordsSize);
