option(CUTFIG_USE_NANA "Enable compilation of Nana GUI sample" OFF)

if(CUTFIG_USE_NANA)
	message("Using nana")
	add_subdirectory(nana)
endif()

add_executable(cutfig main.cpp arrangement.cpp occupancy.cpp rectangle.cpp stencil.cpp point.cpp cutfig.cpp)
target_link_libraries(
	cutfig PRIVATE project_options project_warnings CONAN_PKG::docopt.cpp CONAN_PKG::fmt CONAN_PKG::spdlog)
