cmake_minimum_required(VERSION 3.16)
set(CMAKE_INSTALL_PREFIX ../)

project(StandardModel)

list(APPEND CMAKE_PREFIX_PATH /home/nyykki/root)
find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})

set(CMAKE_CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_STANDARD 14)

add_executable(all_pt src/all_pt.cpp)
target_link_libraries(all_pt PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS all_pt DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(merge src/merge.cpp)
target_link_libraries(merge PUBLIC ${ROOT_LIBRARIES})
install(TARGETS merge DESTINATION /home/nyykki/Scrivania/histos_root/histos4datacards)


#add_executable(all_E src/all_E.cpp)
#target_link_libraries(all_E PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
#install(TARGETS all_E DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(all_Eta src/all_Eta.cpp)
target_link_libraries(all_Eta PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS all_Eta DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(all_Phi src/all_Phi.cpp)
#target_link_libraries(all_Phi PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
#install(TARGETS all_Phi DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(all_px src/all_px.cpp)
#target_link_libraries(all_px PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
#install(TARGETS all_px DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(all_py src/all_py.cpp)
#target_link_libraries(all_py PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
#install(TARGETS all_py DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(all_pz src/all_pz.cpp)
#target_link_libraries(all_pz PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
#install(TARGETS all_pz DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(all_mll src/all_mll.cpp)
target_link_libraries(all_mll PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS all_mll DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(all_mjj src/all_mjj.cpp)
target_link_libraries(all_mjj PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS all_mjj DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(merge_multipart src/merge_multipart.cpp)
target_link_libraries(merge_multipart PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS merge_multipart DESTINATION /home/nyykki/Scrivania/histos_root/histos4datacards)
