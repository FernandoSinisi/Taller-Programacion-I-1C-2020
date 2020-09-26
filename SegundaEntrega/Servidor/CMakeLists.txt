cmake_minimum_required(VERSION 3.15)
project(Servidor)

set(CMAKE_CXX_STANDARD 11)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Wconversion -Wfloat-equal -Wmissing-include-dirs -Wredundant-decls -Wunused -Werror")
set(CMAKE_C_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Servidor
                main.cpp
                src/modelo/Servidor.cpp
                src/modelo/Servidor.h
                src/controlador/ControladorServidor.cpp
                src/controlador/ControladorServidor.h
                src/controlador/JuegoControlador.cpp
                src/controlador/JuegoControlador.h
                src/modelo/Juego.cpp
                src/modelo/Juego.h
                src/tools/Constantes.cpp
                src/tools/Constantes.h
                src/tools/CargadorDeConfiguracion.cpp
                src/tools/CargadorDeConfiguracion.h
                src/hilos/Hilo.h src/hilos/ColaProtegida.h
        src/hilos/HiloRecibir.cpp
        src/hilos/HiloRecibir.h
        src/hilos/HiloEnviar.cpp
        src/hilos/HiloEnviar.h
                src/tools/Log.cpp
                src/tools/Log.h
                src/tools/Timestamp.cpp
                src/tools/Timestamp.h
                src/modelo/Nivel.h
                src/modelo/Nivel.cpp
                src/modelo/Personaje.h
                src/modelo/Personaje.cpp
                src/modelo/Posicion.h
                src/modelo/Posicion.cpp
                src/modelo/Ventana.h
                src/modelo/Ventana.cpp
                src/modelo/estado_personaje/EstadoPersonaje_I.h
                src/modelo/estado_personaje/PersonajeMoviendose.cpp
                src/modelo/estado_personaje/PersonajeMoviendose.h
                src/modelo/estado_personaje/PersonajeQuieto.cpp
                src/modelo/estado_personaje/PersonajeQuieto.h
                src/tools/Utils.cpp
                src/tools/Utils.h
                src/tools/SDL_Utils.cpp
                src/tools/SDL_Utils.h
                src/modelo/Enemigo.cpp
                src/modelo/Enemigo.h
                src/modelo/estado_enemigo/EstadoEnemigo.h
                src/modelo/estado_enemigo/EnemigoQuieto.cpp
                src/modelo/estado_enemigo/EnemigoQuieto.h
                src/modelo/estado_enemigo/EnemigoInactivo.cpp
                src/modelo/estado_enemigo/EnemigoInactivo.h
                src/modelo/Colisionador.cpp
                src/modelo/Colisionador.h
                src/hilos/HiloAceptador.cpp
                src/hilos/HiloAceptador.h
                src/modelo/Cliente.cpp
                src/modelo/Cliente.h)

target_link_libraries(Servidor SDL2 SDL2_image SDL2_ttf SDL2_mixer jsoncpp pthread)