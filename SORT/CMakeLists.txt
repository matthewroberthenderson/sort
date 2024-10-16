set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} CACHE STRING "" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} CACHE STRING "" )
add_executable(${PNAME} "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
target_link_directories(${PNAME} PUBLIC "${CMAKE_BINARY_DIR}/SDL/Debug")
target_include_directories(${PNAME} PUBLIC "${CMAKE_SOURCE_DIR}/SDL/include")
target_include_directories(${PNAME} PUBLIC "${CMAKE_SOURCE_DIR}/SORT/include")
add_custom_command(TARGET ${PNAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_BINARY_DIR}/SDL/Debug/SDL3.dll" "${CMAKE_BINARY_DIR}/Debug/"
)

target_link_libraries(${PNAME} PUBLIC SDL3)