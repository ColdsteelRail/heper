set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # 定义可执行文件目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)  # 库文件目录

# 编译子目录
# 在cmake执行路径下，创建library文件存放其编译文件
add_subdirectory(library)
#add_subdirectory(examples)