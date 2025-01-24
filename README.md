# XML Editor and Visualizer

<div id="header" align="center">
  <img src="https://github.com/user-attachments/assets/72e4e9b2-d684-4c8a-91a9-ab3f7623adae" alt="header-image">
</div>

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Command Line Interface (CLI)](#command-line-interface-cli)
- [Commands Overview](#commands-overview)
- [Installation](#installation)
- [Support](#support)

---

## Introduction
This project extends the functionality of a normal XML processing tool to provide advanced operations, including validation, correction, data conversion, visualization, and network analysis operations. Also there is a windows version provided to download and use. 

## Features

- **XML Validation**: Detect and fix issues like mismatched or missing tags.
- **Formatting**: Prettify XML with proper indentation for enhacing readability.
- **XML to JSON Conversion**: Transform XML data into JSON file.
- **Minification**: Reduce XML file size by removing unnecessary spaces and newlines.
- **Compression**: Compress XML files into a custom format to save space.
- **Decompression**: Restore compressed XML files to their original format.
- **Visualization**: Visualize social networks as graphs (JPG Image).
- **Network Analysis**: Identify influencers , Active Users, Mutual connections, and friends suggestions.
- **Post Search**: Search posts by a specific word or topic.

---

### **Command Line Interface (CLI)**
Perform quick and efficient operations on XML files via the CLI using the `.exe` executable provided, `xml_editor`:
```bash
./xml_editor [command] -i [input_file] -o [output_file]
```
> [!NOTE]
> Replace `[command]` with one of the available commands listed [below](#commands-overview).
> Replace `[input_file]` and `[output_file]` with the corresponding file names.
--- 

## **Commands Overview**
The following is a comprehensive list of commands available in the XML Editor and example usage for each:

| Command        | Description                                       | Example Command                                              |
|----------------|---------------------------------------------------|--------------------------------------------------------------|
| `verify`       | Validate an XML file and optionally fix it.       | `xml_editor verify -i input_file.xml -o output_file.xml`  |
| `format`       | Prettify an XML file for readability.             | `xml_editor format -i input_file.xml -o output_file.xml` |
| `json`         | Convert XML to JSON format.                       | `xml_editor json -i input_file.xml -o output_file.json`     |
| `mini`         | Minify XML by removing unnecessary spaces.        | `xml_editor mini -i input_file.xml -o output_file.xml`    |
| `compress`     | Compress an XML file into a custom format.        | `xml_editor compress -i input_file.xml -o output_file.comp` |
| `decompress`   | Restore compressed XML to its original form.      | `xml_editor decompress -i input_file.comp -o output_file.xml` |
| `draw`         | Draw XML data as a graph.                         | `xml_editor draw -i input_file.xml -o output_file.jpg`       |
| `most_active`  | Find the most active user in the XML data.        | `xml_editor most_active -i input_file.xml`             |
| `most_influencer` | Find the most influential user in the XML data.| `xml_editor most_influencer -i input_file.xml`         |
| `mutual`       | Find mutual users for given user IDs.             | `xml_editor mutual -i input_file.xml -ids 1,2,3`       |
| `suggest`      | Suggest users for a given user ID.                | `xml_editor suggest -i input_file.xml -id 1`           |
| `search`       | Search posts by word or topic.                    | `xml_editor search -w word -t topic -i input_file.xml  ` |


---

## **Installation**
--------

We provide a Windows version with two modes: **CLI** (Command Line Interface) and **GUI** (Graphical User Interface). You can download the `.zip` file for free from the link below:

📥 [Download Windows Version (CLI & GUI)](https://drive.google.com/file/d/1UOFxqXzBhwSGLq1YxBsHlwkmdiYWKran/view?usp=drive_link)
---

> [!NOTE]
> A small demo video is available to show you how to use the app. [Watch the demo video here](https://drive.google.com/file/d/1WcOU4egqxAGsfKdM39rX4rHtmvLQknBj/view?usp=drive_link).
--- 

## **Support**

If you faced any issues or had questions about this project please **Raise an Issue** in the [GitHub Repository](https://github.com/Ahmed-Tarek-Mahmoud/CSE331-DSA-Project/issues).  

Got feedback or ideas? We're here to listen!
