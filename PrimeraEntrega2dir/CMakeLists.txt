cmake_minimum_required(VERSION 3.15)
project(PrimeraEntrega)

set(CMAKE_CXX_STANDARD 11)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Wconversion -Wfloat-equal -Wmissing-include-dirs -Wredundant-decls -Wunused -Werror")
set(CMAKE_C_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

#add_subdirectory(lib/googletest)
#include_directories(lib/googletest/googletest/include)

add_executable(PrimeraEntrega
        main.cpp
        #test/Timestamptest.cpp
        src/controller/JuegoControlador.h
        src/controller/JuegoControlador.cpp
        src/model/Nivel.h
        src/model/Nivel.cpp
        src/model/Personaje.cpp
        src/model/Personaje.h
        src/model/Posicion.cpp
        src/model/Posicion.h
        src/model/Enemigo.cpp
        src/model/Enemigo.h
        src/model/estado_enemigo/EstadoEnemigo.h
        src/model/estado_enemigo/EnemigoQuieto.cpp
        src/model/estado_enemigo/EnemigoQuieto.h
        src/model/estado_enemigo/EnemigoInactivo.cpp
        src/model/estado_enemigo/EnemigoInactivo.h
        src/model/estado_personaje/EstadoPersonaje_I.h
        src/model/estado_personaje/PersonajeQuieto.cpp
        src/model/estado_personaje/PersonajeQuieto.h
        src/model/estado_personaje/PersonajeMoviendose.cpp
        src/model/estado_personaje/PersonajeMoviendose.h
        src/view/JuegoVista.h
        src/view/JuegoVista.cpp
        src/view/PersonajeVista.cpp
        src/view/PersonajeVista.h
        src/view/EnemigoVista.cpp
        src/view/EnemigoVista.h
        src/tools/Timestamp.h
        src/tools/Timestamp.cpp
        src/tools/Constantes.h
        src/tools/Log.h
        src/tools/Log.cpp
        src/tools/CargadorDeConfiguracion.cpp 
        src/tools/CargadorDeConfiguracion.h
        src/tools/ParserEstadoJuego.cpp
        src/tools/ParserEstadoJuego.h
        src/tools/SDL_Utils.cpp
        src/tools/SDL_Utils.h
        src/tools/Utils.cpp
        src/tools/Utils.h
        src/model/CartelNivel.cpp
        src/model/CartelNivel.h
        src/controller/CartelNivelControlador.cpp
        src/controller/CartelNivelControlador.h
        src/view/CartelNivelVista.cpp src/tools/Constantes.cpp
        src/view/FondoVista.h
        src/view/FondoVista.cpp
        src/view/NivelVista.h
        src/view/NivelVista.cpp
        src/model/estado_enemigo/EnemigoInactivo.cpp
        src/model/estado_enemigo/EnemigoInactivo.h
        src/model/Ventana.cpp
        src/model/Ventana.h
        src/view/CargadorTexturasEnemigos.cpp
        src/view/CargadorTexturasEnemigos.h
        src/model/Colisionador.cpp
        src/model/Colisionador.h
        src/model/Juego.cpp
        src/model/Juego.h)

#target_link_libraries(PrimeraEntrega gtest gtest_main SDL2 SDL2_image SDL2_ttf SDL2_mixer)
target_link_libraries(PrimeraEntrega SDL2 SDL2_image SDL2_ttf SDL2_mixer jsoncpp)