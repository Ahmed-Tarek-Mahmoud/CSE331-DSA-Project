#include "minifier.hpp"

void minifyXMLFiles(const char *inputFile, const char *outputFile)
{
    string minifiedXml = minifyXML(inputFile);

    if (minifiedXml.empty())
    {
        return; // input file is not found
    }

    FILE *outFile = fopen(outputFile, "r");
    if (!outFile)
    {
        char newOutputFile[265];
        snprintf(newOutputFile, sizeof(newOutputFile), "%s", outputFile);
        outFile = fopen(newOutputFile, "w");
        if (!outFile)
        {
            fprintf(stderr, "Error: Could not create output file: %s\n", newOutputFile);
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

            return;
        }
    }

    for (int i = 0; i < minifiedXml.length(); i++)
    {
        fputc(minifiedXml[i], outFile); // copy the minified string to output file
    }

    fclose(outFile);
    printf("Minified XML has been written.\n");
}

string minifyXML(const char *inputFile)
{
    FILE *inFile = fopen(inputFile, "r");
    if (!inFile)
    {
        fprintf(stderr, "Error: Could not open input file: %s\n", inputFile);
        return "";
    }

    char ch;
    bool insideTag = false;        // True when inside `<...>`
    bool insideData = false;       // True when inside meaningful data
    bool lastCharWasSpace = false; // Tracks if the last character was a space
    string minifiedXml;

    while ((ch = fgetc(inFile)) != EOF)
    {
        if (ch == '<')
        {
            insideTag = true;
            insideData = false;
            lastCharWasSpace = false; // Reset space tracking

            minifiedXml += ch;
        }
        else if (ch == '>')
        {
            insideTag = false;
            lastCharWasSpace = false; // Reset space tracking
            minifiedXml += ch;
        }
        else if (insideTag)
        {
            // Write characters directly if inside a tag
            minifiedXml += ch;
        }
        else if (!isspace(ch))
        {
            // If a non-space character is encountered, it starts meaningful data
            insideData = true;

            if (lastCharWasSpace)
            {
                minifiedXml += ' '; // Write a single space before data
            }
            lastCharWasSpace = false; // Reset space tracking

            minifiedXml += ch;
        }
        else if (insideData)
        {
            // Only track a single space if meaningful data follows
            lastCharWasSpace = true;
        }
    }

    fclose(inFile);
    return minifiedXml;
}
