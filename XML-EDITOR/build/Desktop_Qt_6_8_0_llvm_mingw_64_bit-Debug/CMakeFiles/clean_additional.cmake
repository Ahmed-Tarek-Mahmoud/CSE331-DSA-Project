# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\XML-EDITOR_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\XML-EDITOR_autogen.dir\\ParseCache.txt"
  "XML-EDITOR_autogen"
  )
endif()
