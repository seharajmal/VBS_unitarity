# Install script for directory: /home/nyykki/Scrivania/histos_root

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "../")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_pt" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_pt")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_pt"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/nyykki/Scrivania/histos_root/all_pt")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/nyykki/Scrivania/histos_root" TYPE EXECUTABLE FILES "/home/nyykki/Scrivania/histos_root/build/all_pt")
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_pt" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_pt")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_pt"
         OLD_RPATH "/home/nyykki/Scrivania/histos_root:/home/nyykki/root/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_pt")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/nyykki/Scrivania/histos_root/histos4datacards/merge")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/nyykki/Scrivania/histos_root/histos4datacards" TYPE EXECUTABLE FILES "/home/nyykki/Scrivania/histos_root/build/merge")
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge"
         OLD_RPATH "/home/nyykki/root/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_Eta" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_Eta")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_Eta"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/nyykki/Scrivania/histos_root/all_Eta")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/nyykki/Scrivania/histos_root" TYPE EXECUTABLE FILES "/home/nyykki/Scrivania/histos_root/build/all_Eta")
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_Eta" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_Eta")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_Eta"
         OLD_RPATH "/home/nyykki/Scrivania/histos_root:/home/nyykki/root/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_Eta")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mll")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mll"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/nyykki/Scrivania/histos_root/all_mll")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/nyykki/Scrivania/histos_root" TYPE EXECUTABLE FILES "/home/nyykki/Scrivania/histos_root/build/all_mll")
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mll")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mll"
         OLD_RPATH "/home/nyykki/Scrivania/histos_root:/home/nyykki/root/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mll")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mjj" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mjj")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mjj"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/nyykki/Scrivania/histos_root/all_mjj")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/nyykki/Scrivania/histos_root" TYPE EXECUTABLE FILES "/home/nyykki/Scrivania/histos_root/build/all_mjj")
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mjj" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mjj")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mjj"
         OLD_RPATH "/home/nyykki/Scrivania/histos_root:/home/nyykki/root/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/all_mjj")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge_multipart" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge_multipart")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge_multipart"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/nyykki/Scrivania/histos_root/histos4datacards/merge_multipart")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/nyykki/Scrivania/histos_root/histos4datacards" TYPE EXECUTABLE FILES "/home/nyykki/Scrivania/histos_root/build/merge_multipart")
  if(EXISTS "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge_multipart" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge_multipart")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge_multipart"
         OLD_RPATH "/home/nyykki/Scrivania/histos_root:/home/nyykki/root/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/nyykki/Scrivania/histos_root/histos4datacards/merge_multipart")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/nyykki/Scrivania/histos_root/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
