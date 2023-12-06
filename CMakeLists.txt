cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(domis4cpp)
include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "DOMIS4CPP")
set(VITA_TITLEID  "DOMIS4CPP")
set(VITA_VERSION  "01.00")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${VITASDK}/arm-vita-eabi/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${VITASDK}/arm-vita-eabi/include/c++/10.3.0")

link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/app/src
    ${VITASDK}/arm-vita-eabi/include
    ${VITASDK}/arm-vita-eabi/include/c++/10.3.0
    ${VITASDK}/arm-vita-eabi/include/common
)

add_executable(${PROJECT_NAME}
  app/src/main.cpp
  app/src/game/atlas/atlas.cpp
  app/src/game/entity/entity.cpp
  app/src/game/fps-limiter/fps-limiter.cpp
  app/src/game/sprite/sprite.cpp
  app/src/game/titlescreen/entities/titlescreen-entity.cpp
  app/src/game/titlescreen/entities/titlescreen-selector-entity.cpp
  app/src/game/titlescreen/titlescreen-module.cpp
  app/src/game/game-module.cpp
)

target_link_libraries(${PROJECT_NAME}
  vita2d
  SceDisplay_stub
  SceGxm_stub
  SceSysmodule_stub
  SceCtrl_stub
  ScePgf_stub
  ScePvf_stub
  SceCommonDialog_stub
  freetype
  png
  jpeg
  z
  m
  c
  SceAppMgr_stub
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE assets/titlescreen/list.png assets/titlescreen/list.png
  FILE assets/titlescreen/right0.png assets/titlescreen/right0.png
  FILE assets/titlescreen/right1.png assets/titlescreen/right1.png
  FILE assets/titlescreen/right2.png assets/titlescreen/right2.png
  FILE assets/titlescreen/selector.png assets/titlescreen/selector.png
  FILE assets/titlescreen/titlescreen.png assets/titlescreen/titlescreen.png
  FILE assets/image.png assets/image.png
)