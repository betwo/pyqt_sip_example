cmake_minimum_required(VERSION 2.8.3)
project(qt_widgets)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED)
 	
find_package(Qt5 COMPONENTS Core Widgets OpenGL REQUIRED)

catkin_python_setup()

catkin_package(
    CATKIN_DEPENDS python_qt_binding
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_definitions(-DQT_NO_KEYWORDS)


find_package(python_qt_binding REQUIRED)
include(${python_qt_binding_EXTRAS_DIR}/sip_helper.cmake)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(${PROJECT_NAME}
  src/widget.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
 )

 target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::OpenGL)


 # python binding



set(qt_widgets_HDRS_DIR ${PROJECT_SOURCE_DIR}/include/qt_widgets)
set(SIP_BUILD_DIR ${PROJECT_SOURCE_DIR}/build/sip/qt_widgets_sip)
set(SIP_SRC_DIR ${PROJECT_SOURCE_DIR}/src/python_bindings/sip)

set(qt_widgets_sip_DEPENDENT_FILES
  sip/qt_widgets.sip
  sip/widget.sip
  ${qt_widgets_HDRS_DIR}/widget.h
)


# maintain context for different named target
set(qt_widgets_sip_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/include "${PROJECT_SOURCE_DIR}/src" ${catkin_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS})
set(qt_widgets_sip_LIBRARIES ${qt_widgets_LIBRARIES} ${PROJECT_NAME})
set(qt_widgets_sip_LIBRARY_DIRS ${qt_widgets_LIBRARY_DIRS} ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_LIB_DESTINATION})
set(qt_widgets_sip_LDFLAGS_OTHER ${qt_widgets_LDFLAGS_OTHER} -Wl,-rpath,\\"${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_LIB_DESTINATION}\\")

# \"

if(sip_helper_FOUND)
  list(APPEND qt_widgets_BINDINGS "sip")
  set(qt_widgets_BINDINGS "${qt_widgets_BINDINGS}" PARENT_SCOPE)
  build_sip_binding(qt_widgets_sip ${CMAKE_CURRENT_LIST_DIR}/sip/qt_widgets.sip
    SIP_CONFIGURE ${python_qt_binding_EXTRAS_DIR}/sip_configure.py
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/sip
    LIBRARY_DIR ${CATKIN_DEVEL_PREFIX}/${PYTHON_INSTALL_DIR}/qt_widgets
    BINARY_DIR ${CATKIN_DEVEL_PREFIX}/bin
    DEPENDS ${qt_widgets_sip_DEPENDENT_FILES}
    DEPENDENCIES qt_widgets
  )
  set(qt_widgets_sip_LIBRARY_FILE libqt_widgets_sip${CMAKE_SHARED_LIBRARY_SUFFIX})
  install(FILES ${CATKIN_DEVEL_PREFIX}/${PYTHON_INSTALL_DIR}/qt_widgets/${qt_widgets_sip_LIBRARY_FILE}
    DESTINATION ${CATKIN_PACKAGE_PYTHON_DESTINATION})
endif()