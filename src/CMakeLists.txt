set(SRC_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${SRC_INCLUDE_DIR})

set(SRC_SOURCES
#  D3D12HelloWindow.cpp
#  DXSample.cpp
#  Main.cpp
#  stdafx.cpp
  source.cpp
  )

add_executable(HelloDX12 WIN32
  ${SRC_SOURCES})
  
target_link_libraries(HelloDX12
  d3d11
  dxgi)
