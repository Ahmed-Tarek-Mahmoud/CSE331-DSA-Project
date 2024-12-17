#pragma once

#include "headers.h"

#define MAX_FILE_NAME_SIZE 265 // max chars to represent output file name

/**
 * @brief Minifies an XML file by removing unnecessary whitespace and newlines outside of tags or data fields.
 *
 * This function reads an input XML file, removes extra spaces and newlines outside of meaningful content,
 * and return the minified version as a string.
 *
 *
 * @param inputFile A string containing the path to the input XML file. The file must exist and be readable.
 * @return A string containing the minified XML content.
 *
 * @note
 * - Spaces inside tags (e.g., between attributes) and within data fields are preserved.
 * - Assumes input files contain well-formed XML.
 *
 *
 * // Function Call
 * minifyXML("input.xml");
 *
 *
 * @throws Prints an error message and returns an empty string if:
 * - The input file cannot be opened.
 */

string minifyXML(const char *inputFile);

/**
 * @brief Minifies an XML file and writes the result to an output file.
 *
 * This function reads an input XML file, minifies its content, and writes the minified XML to the specified
 * output file. If the output file does not exist, it is automatically created. If it already exists,
 * its content is overwritten.
 *
 * @param inputFile A string containing the name of the input XML file. The file must exist and be readable.
 * @param outputFile A string containing the name of the output XML file. If the file does not exist, it will be created.
 *
 * @note
 * - This function calls `minifyXML_modified` to perform the minification.
 * - Any errors related to file operations (e.g., read/write issues) are printed to `stderr`.
 *
 * @throws Prints an error message and exits the function if:
 * - The input file cannot be opened.
 * - The output file cannot be created or written to.
 */

void minifyXMLFiles(const char *inputFile, const char *outputFile);