# Install script for directory: C:/Users/doget/source/repos/sfml/vcpkg_installed/vcpkg/blds/sfml/src/2.6.0-2d6a42d05d.clean/src/SFML

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/doget/source/repos/sfml/vcpkg_installed/vcpkg/pkgs/sfml_x64-windows")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/doget/source/repos/sfml/vcpkg_installed/vcpkg/blds/sfml/x64-windows-rel/src/SFML/System/cmake_install.cmake")
  include("C:/Users/doget/source/repos/sfml/vcpkg_installed/vcpkg/blds/sfml/x64-windows-rel/src/SFML/Main/cmake_install.cmake")
  include("C:/Users/doget/source/repos/sfml/vcpkg_installed/vcpkg/blds/sfml/x64-windows-rel/src/SFML/Window/cmake_install.cmake")
  include("C:/Users/doget/source/repos/sfml/vcpkg_installed/vcpkg/blds/sfml/x64-windows-rel/src/SFML/Network/cmake_install.cmake")
  include("C:/Users/doget/source/repos/sfml/vcpkg_installed/vcpkg/blds/sfml/x64-windows-rel/src/SFML/Graphics/cmake_install.cmake")
  include("C:/Users/doget/source/repos/sfml/vcpkg_installed/vcpkg/blds/sfml/x64-windows-rel/src/SFML/Audio/cmake_install.cmake")

endif()

