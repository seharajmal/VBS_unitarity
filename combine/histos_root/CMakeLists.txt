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

add_executable(all_deltaEtajj src/all_deltaEtajj.cpp)
target_link_libraries(all_deltaEtajj PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS all_deltaEtajj DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(all_deltaPhijj src/all_deltaPhijj.cpp)
target_link_libraries(all_deltaPhijj PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS all_deltaPhijj DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

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

add_executable(ciplots src/ciplots.cpp)
target_link_libraries(ciplots PUBLIC ${ROOT_LIBRARIES})
install(TARGETS ciplots DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(comparing_ci src/comparing_ci.cpp)
target_link_libraries(comparing_ci PUBLIC ${ROOT_LIBRARIES})
install(TARGETS comparing_ci DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(distributions src/distributions.cpp)
target_link_libraries(distributions PUBLIC ${ROOT_LIBRARIES})
install(TARGETS distributions DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(distributions_SMvsEFT src/distributions_SMvsEFT.cpp)
target_link_libraries(distributions_SMvsEFT PUBLIC ${ROOT_LIBRARIES})
install(TARGETS distributions_SMvsEFT DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(bin_count src/bin_count.cpp)
target_link_libraries(bin_count PUBLIC ${ROOT_LIBRARIES})
install(TARGETS bin_count DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(significanza src/significanza.cpp)
target_link_libraries(significanza PUBLIC ${ROOT_LIBRARIES})
install(TARGETS significanza DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(significanza2 src/significanza2.cpp)
target_link_libraries(significanza2 PUBLIC ${ROOT_LIBRARIES})
install(TARGETS significanza2 DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(LS_all_obs src/LS_all_obs.cpp)
target_link_libraries(LS_all_obs PUBLIC ${ROOT_LIBRARIES})
install(TARGETS LS_all_obs DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(LSplot src/LSplot.cpp)
target_link_libraries(LSplot PUBLIC ${ROOT_LIBRARIES})
install(TARGETS LSplot DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(all_mjj src/all_mjj.cpp)
target_link_libraries(all_mjj PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS all_mjj DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

#add_executable(phi src/phi.cpp)
#target_link_libraries(phi PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
#install(TARGETS phi DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(merge_multipart src/merge_multipart.cpp)
target_link_libraries(merge_multipart PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/histos_root/libExRootAnalysis.so)
install(TARGETS merge_multipart DESTINATION /home/nyykki/Scrivania/histos_root/histos4datacards)






