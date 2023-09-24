 # oifw only supports Qt 6.
cmake_minimum_required(VERSION 3.5)

project(oifw VERSION 0.1 LANGUAGES CXX)

set(LANGUAGE CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

if(NOT MINGW)
    message(FATAL_ERROR "Because of linkage differences between compilers,\n${PROJECT_NAME} currently only supports MinGW.")
endif()

# Qt
set(STATIC_QT_DIR ${CMAKE_SOURCE_DIR}/qt-static/qtbase-patched)
list(APPEND CMAKE_MODULE_PATH ${STATIC_QT_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${STATIC_QT_DIR}/lib/cmake)

find_package(QT NAMES Qt6 EXACT 6.5.2 REQUIRED PATHS ${STATIC_QT_DIR} NO_DEFAULT_PATH REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} EXACT 6.5.2 REQUIRED PATHS ${STATIC_QT_DIR} NO_DEFAULT_PATH REQUIRED COMPONENTS Core Gui Widgets)

if(NOT QT_FOUND)
    message(FATAL_ERROR "Static Qt not found in ${STATIC_QT_DIR}.\nPlease run the build script (${CMAKE_SOURCE_DIR}/qt-static/build.sh)")
endif()

if(NOT QT_VERSION_MAJOR EQUAL 6)
    message(FATAL_ERROR "${PROJECT_NAME} only supports Qt 6.")
endif()

message(STATUS "Found static Qt ${Qt6Core_VERSION}")

set(QT_SOURCES # hmm
    ${STATIC_QT_DIR}/src/plugins/platforms/windows/.rcc/cursors.qrc
    ${STATIC_QT_DIR}/src/plugins/platforms/windows/.rcc/openglblacklists.qrc
    ${STATIC_QT_DIR}/src/widgets/.rcc/qmessagebox.qrc
    ${STATIC_QT_DIR}/src/widgets/.rcc/qstyle.qrc
)

# Project
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        bannerwidget.h bannerwidget.cpp
        footerwidget.h footerwidget.cpp

        mainwindow.ui
        resource.qrc
)
qt_add_executable(oifw
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    ${QT_SOURCES}
)
qt_import_plugins(oifw
    INCLUDE Qt::QWindowsIntegrationPlugin Qt::QWindowsVistaStylePlugin
)

# Link-time and size-focused optimizations
set(CMAKE_CXX_FLAGS_RELEASE "-Oz -s")
set(CMAKE_C_FLAGS_RELEASE "-Oz -s")
set_property(TARGET oifw PROPERTY WIN32_EXECUTABLE true)
set_property(TARGET oifw PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

# Static runtime
target_compile_features(oifw PUBLIC cxx_std_20)
set(STATIC_RUNTIME_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${STATIC_RUNTIME_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${STATIC_RUNTIME_FLAGS}")

# Includes
file(GLOB STATIC_QT_INCLUDE_PATHS ${STATIC_QT_DIR}/include/*)
target_include_directories(oifw PRIVATE ${STATIC_QT_DIR}/src/corelib ${STATIC_QT_DIR}/include ${STATIC_QT_INCLUDE_PATHS} ${CMAKE_SOURCE_DIR})

# Libraries
file(GLOB STATIC_QT_LIBS ${STATIC_QT_DIR}/lib/*.a)
set(LINK_LIBS
    b2
    brotlicommon
    brotlidec
    bz2
    d3d9
    d3d11
    dcomp
    double-conversion
    dwmapi
    dwrite
    dxgi
    freetype
    imm32
    md4c
    pcre2-16
    png
    runtimeobject
    setupapi
    shcore
    shlwapi
    uxtheme
    version
    wtsapi32
    z
    zstd
    ${STATIC_QT_LIBS}
    ${STATIC_QT_DIR}/plugins/platforms/libqwindows.a
    ${STATIC_QT_DIR}/plugins/styles/libqwindowsvistastyle.a

)
target_link_libraries(oifw PRIVATE
    ${STATIC_RUNTIME_FLAGS} -static
    "$<LINK_GROUP:RESCAN,${LINK_LIBS}>"
)

# Finalize
qt_finalize_executable(oifw)
