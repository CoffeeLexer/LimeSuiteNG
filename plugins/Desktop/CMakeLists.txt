if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
    return()
endif()

include(FeatureSummary)
include(CMakeDependentOption)
cmake_dependent_option(ENABLE_DESKTOP "Enable LimeSuiteNG launcher and icons" ON "ENABLE_GUI" OFF)
add_feature_info(DESKTOP ENABLE_DESKTOP "LimeSuiteNG freedesktop integration")
if(NOT ENABLE_DESKTOP)
    return()
endif()

########################################################################
# menu launcher and MIME type
########################################################################
file(GLOB lime_suite_png_icons ${CMAKE_CURRENT_SOURCE_DIR}/lime-suite-*.png)

install(FILES lime-suite.desktop ${lime_suite_png_icons} DESTINATION share/Lime/Desktop)

########################################################################
# install/uninstall scripts
########################################################################
install(PROGRAMS install uninstall DESTINATION share/Lime/Desktop)
