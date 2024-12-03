#include "minifier.hpp"

void minifyXML(const char *inputFile, const char *outputFile)
{
    FILE *inFile = fopen(inputFile, "r");
    if (!inFile)
    {
        fprintf(stderr, "Error: Could not open input file: %s\n", inputFile);
        return;
    }

    // Check if the output file exists, if not create one
    FILE *outFile = fopen(outputFile, "r");
    if (!outFile)
    {
        char newOutputFile[BUFFER_SIZE];
        snprintf(newOutputFile, sizeof(newOutputFile), "%s", outputFile);
        outFile = fopen(newOutputFile, "w");
        if (!outFile)
        {
            fprintf(stderr, "Error: Could not create output file: %s\n", newOutputFile);
            fclose(inFile);
            return;
        }
        printf("Output file does not exist. Created file: %s\n", newOutputFile);
    }
    else
    {
        fclose(outFile); // Close to reopen in write mode
        outFile = fopen(outputFile, "w");
        if (!outFile)
        {
            fprintf(stderr, "Error: Could not open output file: %s\n", outputFile);
            fclose(inFile);
            return;
        }
    }

    char ch;
    bool insideTag = false;   // True when inside `<...>`
    bool insideData = false;  // True when inside meaningful data
    bool dataStarted = false; // Tracks the beginning of meaningful data
    char buffer[256];         // Temporary buffer to accumulate spaces
    int bufferIndex = 0;

    while ((ch = fgetc(inFile)) != EOF)
    {
        if (ch == '<')
        {
            insideTag = true;
            insideData = false;

            // Flush any buffered spaces when entering a tag
            bufferIndex = 0; // Clear buffer
            fputc(ch, outFile);
        }
        else if (ch == '>')
        {
            insideTag = false;
            dataStarted = false; // End of a tag
            fputc(ch, outFile);
        }
        else if (insideTag)
        {
            // Write characters directly if inside a tag
            fputc(ch, outFile);
        }
        else if (!isspace(ch))
        {
            // If a non-space character is encountered, it starts meaningful data
            insideData = true;
            dataStarted = true;

            // Flush buffered spaces
            for (int i = 0; i < bufferIndex; i++)
            {
                fputc(buffer[i], outFile);
            }
            bufferIndex = 0; // Clear buffer

            fputc(ch, outFile);
        }
        else if (insideData)
        {
            // Accumulate spaces for meaningful data
            if (bufferIndex < sizeof(buffer) - 1)
            {
                buffer[bufferIndex++] = ch;
            }
        }
    }

    fclose(inFile);
    fclose(outFile);
    printf("Minified XML has been written.\n");
}
