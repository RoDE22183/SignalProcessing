
cmake_minimum_required(VERSION 3.15)
project(WaveformGenerator VERSION 1.0.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)





set(LIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/sinwave.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/squarewave.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/triangelwave.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/dsp.cpp"
    
)

add_library(waveform_generator STATIC ${LIB_SOURCES})

target_compile_features(waveform_generator
    PUBLIC
        cxx_std_20
)

target_include_directories(waveform_generator
    PUBLIC
        inc
)

target_link_libraries(waveform_generator
    PUBLIC
    ${CONAN_LIBS}
)

# Executable
set(EXE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)
add_executable(waveform_generator-exe ${EXE_SOURCES})
target_compile_features(waveform_generator-exe
    PRIVATE
        cxx_std_20
)
target_compile_definitions(waveform_generator-exe
    PRIVATE
        $<$<PLATFORM_ID:Windows>:_WIN32_WINNT=${WINDOWS_VERSION}>
)
target_compile_options(waveform_generator-exe
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/bigobj>
)
target_link_libraries(waveform_generator-exe
    PRIVATE
    waveform_generator
    ${CONAN_LIBS}
)




