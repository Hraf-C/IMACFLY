find_package (Doxygen)

message("imacfly_SOURCE_DIR     " ${c3ga_SOURCE_DIR})
message("imacfly_BINARY_DIR     " ${c3ga_BINARY_DIR})
message("DOXYGEN_EXECUTABLE  " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (${imacfly_SOURCE_DIR}/doc/Doxyfile-html.cmake ${imacfly_BINARY_DIR}/doc/Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} ${imacfly_BINARY_DIR}/doc/Doxyfile-html)
endif (DOXYGEN_FOUND)
