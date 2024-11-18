# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TaskManagerApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TaskManagerApp_autogen.dir\\ParseCache.txt"
  "TaskManagerApp_autogen"
  )
endif()
