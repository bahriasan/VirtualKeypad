# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\KeyPad_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\KeyPad_autogen.dir\\ParseCache.txt"
  "KeyPad_autogen"
  )
endif()
