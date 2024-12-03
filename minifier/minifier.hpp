#pragma once

#include "headers.h"

#define BUFFER_SIZE 265 // max number of consecutive white spaces

/**
 * @brief Minifies an XML file by removing unnecessary whitespace and newlines outside of tags or data fields.
 *
 * This function reads an input XML file, removes extra spaces and newlines outside of meaningful content,
 * and writes the minified version to an output file.
 *
 * If the specified output file does not exist, the function automatically creates
 * a new file with the same name and a `.xml` extension.
 *
 * @param inputFile A string containing the path to the input XML file. The file must exist and be readable.
 * @param outputFile A string containing the desired path for the output XML file. If the file does not exist,
 *        a new file with the same name and a `.xml` extension is created.
 *
 * @note
 * - Spaces inside tags (e.g., between attributes) and within data fields are preserved.
 * - Assumes input files contain well-formed XML.
 *
 *
 * // Function Call
 * minifyXML("input.xml", "output.xml");
 *
 *
 * @throws Prints an error message and exits the function if:
 * - The input file cannot be opened.
 * - The output file cannot be created or written to.
 */

void minifyXML(const char *inputFile, const char *outputFile);