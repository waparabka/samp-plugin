cmake_minimum_required (VERSION 3.0)

project ("samp-plugin")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

include(FetchContent)

FetchContent_Declare(sampapi GIT_REPOSITORY https://github.com/BlastHackNet/SAMP-API.git GIT_TAG f89b35edb7eaf5db374e32a63f2366c4bb714418)
FetchContent_Declare(ktsignal GIT_REPOSITORY https://github.com/kin4stat/ktsignal.git GIT_TAG f08a19d9a00ad5284871bf44178d835da7b26ebf)
FetchContent_Declare(kthook GIT_REPOSITORY https://github.com/kin4stat/kthook.git GIT_TAG 21ca70481273d1efcc98ca49063178e46277009b)
FetchContent_Declare(xbyak GIT_REPOSITORY https://github.com/herumi/xbyak.git GIT_TAG 1c35e34abc359d14d7cba2505f2c851354298f5c)
FetchContent_Declare(rakhook GIT_REPOSITORY https://github.com/waparabka/rakhook.git)
FetchContent_MakeAvailable(sampapi ktsignal kthook xbyak rakhook)

add_library(${PROJECT_NAME} SHARED)

target_link_libraries(${PROJECT_NAME} PUBLIC sampapi kthook xbyak rakhook)
target_sources(${PROJECT_NAME} PRIVATE source/main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME} SUFFIX ".asi")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)