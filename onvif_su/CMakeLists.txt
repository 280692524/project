cmake_minimum_required(VERSION 2.8.12)

project(onvif_a)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -w -pipe -O2 -Wall -Wpointer-arith -Wunused-parameter -Werror -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches  -mtune=generic -fPIC -ffunction-sections -fdata-sections -fpermissive -ffast-math -Wmissing-declarations -Wunused-function -Wshadow -Wno-unused-parameter -Wno-write-strings -DWITH_OPENSSL")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w -pipe -O2 -Wall -Wno-implicit-fallthrough -Wpointer-arith -Wno-unused-parameter -Werror -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches -mtune=generic -fPIC -ffunction-sections -fdata-sections -ffast-math -Wmissing-declarations -Wnested-externs -Wshadow -Wunused-function -DWITH_OPENSSL -D__ANDROID__ -DANDROID ")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-z,relro -Wl,-z,now -pie  -Wl,-E  -Wl,--gc-sections  ")
set(CMAKE_MODULE_LINKER_FLAGS "-Wl,-z,relro -Wl,-z,now -pie  -Wl,-E  -Wl,--gc-sections ")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-z,relro -Wl,-z,now -pie  -Wl,-E  -Wl,--gc-sections ")





##############################################
include_directories(${CMAKE_CURRENT_LIST_DIR_EDGE} ./include )
#链接库的路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)  ##CMAKE_CURRENT_SOURCE_DIR是当前处理的CMakeLists.txt所在的目录
#添加源代码
aux_source_directory(./src DIR_SRCS )
#生成可执行文件
add_executable(onvif_su ${DIR_SRCS} ${CMAKE_CURRENT_LIST_DIR_EDGE} )

#生成共享库，可执行文件共用
target_link_libraries(onvif_su -lssl -lcrypto -lonvif)
