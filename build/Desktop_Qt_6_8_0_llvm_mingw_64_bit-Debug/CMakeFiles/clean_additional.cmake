# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GUI-xml_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GUI-xml_autogen.dir\\ParseCache.txt"
  "GUI-xml_autogen"
  )
endif()
