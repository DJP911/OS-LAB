#include <stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char buffer[1024];
    int numBytes;

    printf("Enter source file path: ");
    scanf("%s", sourcePath);

    printf("Enter target file path: ");
    scanf("%s", targetPath);

    // Open source file for reading
    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    // Open target file for writing
    targetFile = fopen(targetPath, "wb");
    if (targetFile == NULL) {
        printf("Unable to create target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy contents from source to target file
    while ((numBytes = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, numBytes, targetFile);
    }

    // Close file pointers
    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");

    return 0;
}
