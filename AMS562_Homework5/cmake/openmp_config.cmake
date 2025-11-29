if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /opt/homebrew/opt/libomp /usr/local)
    find_package(OpenMP)

    if(NOT OpenMP_CXX_FOUND)
        string(ASCII 27 Esc)
        set(Yellow "${Esc}[33m")
        set(ColorReset "${Esc}[m")
        message(STATUS
            "\n${Yellow}OpenMP was not found. To use OpenMP for Apple Clang, please install libomp by running:\n"
            "      brew install libomp\n"
            "After installation, re-run cmake to configure your project again.${ColorReset}\n")
    else()
        # Add OpenMP include and library directories for AppleClang
        find_path(OPENMP_INCLUDE_DIR omp.h)
        include_directories(${OPENMP_INCLUDE_DIR})

        find_library(OPENMP_LIBRARY omp)
        get_filename_component(OPENMP_LIB_DIR ${OPENMP_LIBRARY} DIRECTORY)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L${OPENMP_LIB_DIR} -lomp")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -L${OPENMP_LIB_DIR} -lomp")
    endif()
else()
    find_package(OpenMP)
endif()

if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP support enabled.")
    SET(USE_OPENMP ON)

    # Set OpenMP compiler and linker flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
else()
    if(USE_OPENMP_USER_SET)
        message(FATAL_ERROR "OpenMP was explicitly enabled but not found.")
    else()
        set(USE_OPENMP OFF)
    endif()
endif()
