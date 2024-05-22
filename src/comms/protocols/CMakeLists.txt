set(PROTOCOLS_NAME "lime-comms-protocols")

add_library(${PROTOCOLS_NAME}
    LMS64CProtocol.cpp)

target_include_directories(${PROTOCOLS_NAME} PRIVATE ../)
target_include_directories(${PROTOCOLS_NAME} PRIVATE ./)