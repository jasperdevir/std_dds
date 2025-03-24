cmake_minimum_required(VERSION 3.10)

project(STD_DDS)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SRCDIR ${CMAKE_SOURCE_DIR}/src)
set(EXAMPLESDIR ${CMAKE_SOURCE_DIR}/examples)

set(BINDIR ${CMAKE_SOURCE_DIR}/bin)

file(MAKE_DIRECTORY ${BINDIR})

add_executable(e_array_list ${EXAMPLESDIR}/e_array_list.c ${SRCDIR}/array_list.c)
target_include_directories(e_array_list PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(e_array_list PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINDIR})

add_executable(e_d_linked_list ${EXAMPLESDIR}/e_d_linked_list.c ${SRCDIR}/d_linked_list.c)
target_include_directories(e_d_linked_list PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(e_d_linked_list PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINDIR})

add_executable(e_graph ${EXAMPLESDIR}/e_graph.c ${SRCDIR}/graph_adj_mat.c)
target_include_directories(e_graph PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(e_graph PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINDIR})

add_executable(e_linked_list ${EXAMPLESDIR}/e_linked_list.c ${SRCDIR}/linked_list.c)
target_include_directories(e_linked_list PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(e_linked_list PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINDIR})

add_executable(e_queue ${EXAMPLESDIR}/e_queue.c ${SRCDIR}/queue.c ${SRCDIR}/d_linked_list.c)
target_include_directories(e_queue PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(e_queue PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINDIR})

add_executable(e_stack ${EXAMPLESDIR}/e_stack.c ${SRCDIR}/stack.c ${SRCDIR}/linked_list.c)
target_include_directories(e_stack PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(e_stack PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINDIR})
