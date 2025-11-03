
void removeWhiteSpace(char fileData[][200], int* fileSize);
void removeWords(char fileData[][200], int* fileSize, char keywords[][200], int keywordsSize);
void removeComments(char fileData[][200],int* fileSize);
void removeStrings(char fileData[][200],int* fileSize);
void resolveEmptyLines(char fileData[][200], int* fileSize);
void resolveOneCharLines(char fileData[][200], int* fileSize);
void PreprocessFile(char fileData[][200],int* fileSize, char keywords[][200], int keywordsSize);
