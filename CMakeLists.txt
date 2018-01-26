cmake_minimum_required(VERSION 2.6)

project(HelloDX12)

set(DX_FOULDER "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)")
message("got foulder " ${DX_FOULDER}/Lib/x64})
include_directories("${DX_FOULDER}/Include")#$ENV{INCLUDE})
link_directories("${DX_FOULDER}/Lib/x64")

add_definitions(-DUNICODE -D_UNICODE)

add_subdirectory(src)
