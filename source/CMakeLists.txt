# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  vec2.cpp
  mat2.cpp
  color.cpp
  circle.cpp
  rectangle.cpp
  tests.cpp)
target_link_libraries(tests
  ${GLFW_LIBRARIES})
