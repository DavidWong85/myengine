cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

include_directories(
    src
)

if(MSVC)
    include_directories(
        contrib/msvc15-windows-x86_64/include
    )
    link_directories(
        ${PROJECT_SOURCE_DIR}/contrib/msvc15-windows-x86_64/lib
    )
else()
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s DISABLE_EXCEPTION_CATCHING=0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s DISABLE_EXCEPTION_CATCHING=0")
endif()

add_definitions(-DSDL_MAIN_HANDLED)

add_library(graphics
    src/graphics/graphics.h
    src/graphics/Light.cpp
    src/graphics/Light.h
    src/graphics/Model.cpp
    src/graphics/Model.h
    src/graphics/ShaderProgram.cpp
    src/graphics/ShaderProgram.h
    src/graphics/Texture.cpp
    src/graphics/Texture.h
    src/graphics/VertexArray.cpp
    src/graphics/VertexArray.h
    src/graphics/VertexBuffer.cpp
    src/graphics/VertexBuffer.h
)

if(MSVC OR MINGW)
    target_link_libraries(graphics glew32 opengl32)
else()
    target_link_libraries(graphics GLEW GL)
endif()

add_library(myengine
   src/myengine/myengine.h
   src/myengine/Core.h
   src/myengine/Entity.h
   src/myengine/Component.h
   src/myengine/Transform.h
   src/myengine/Exception.h
   src/myengine/Renderer.h
   src/myengine/Keyboard.h
   src/myengine/Camera.h
   src/myengine/Resource.h
   src/myengine/Resources.h
   src/myengine/Model.h
   src/myengine/Texture.h
   src/myengine/Sound.h
   src/myengine/SoundSource.h

   src/myengine/Core.cpp
   src/myengine/Entity.cpp
   src/myengine/Component.cpp
   src/myengine/Transform.cpp
   src/myengine/Exception.cpp
   src/myengine/Renderer.cpp
   src/myengine/Keyboard.cpp
   src/myengine/Camera.cpp
   src/myengine/Resource.cpp
   src/myengine/Model.cpp
   src/myengine/Texture.cpp
   src/myengine/Sound.cpp
   src/myengine/SoundSource.cpp
)
if(MSVC OR MINGW)
target_link_libraries(myengine graphics SDL2 openal32)
else()
target_link_libraries(myengine graphics SDL2 AL)
endif()

add_executable(demo
    src/demo/main.cpp
    src/demo/CameraController.h
    src/demo/CameraController.cpp
)

target_link_libraries(demo myengine)