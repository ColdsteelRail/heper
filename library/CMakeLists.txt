set(lib_SRCS
    cpuinfo.c
    logging.c
    percentiles.c
    version.c
)

add_library(heper_lib ${lib_SRCS})
#target_link_libraries(heper_library thread) # 多线程

add_subdirectory(test)