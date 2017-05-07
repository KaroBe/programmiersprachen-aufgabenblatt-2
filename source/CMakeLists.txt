# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  color.cpp
  rectangle.cpp
  circle.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  tests.cpp
  vec2.cpp
  mat2.cpp
  color.cpp
  circle.cpp
  rectangle.cpp
  window.cpp
  glew.c
)
target_link_libraries(tests
glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
)