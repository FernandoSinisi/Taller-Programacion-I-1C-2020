cmake_minimum_required(VERSION 3.15)
project(Cliente)

set(CMAKE_CXX_STANDARD 11)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Wconversion -Wfloat-equal -Wmissing-include-dirs -Wredundant-decls -Wunused -Werror")
set(CMAKE_C_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Cliente
        main.cpp
        src/controlador/ControladorCliente.cpp
        src/controlador/ControladorCliente.h
        src/modelo/Cliente.cpp
        src/modelo/Cliente.h
        src/tools/Constantes.cpp
        src/tools/Constantes.h
        src/vista/JuegoVista.cpp
        src/vista/JuegoVista.h
        src/tools/SDL_Utils.cpp
        src/tools/SDL_Utils.h
        src/controlador/JuegoControlador.h
        src/controlador/JuegoControlador.cpp
        src/controlador/MenuJuegoControlador.cpp
        src/controlador/MenuJuegoControlador.h
        src/modelo/MenuJuego.cpp
        src/modelo/MenuJuego.h
        src/vista/MenuJuegoVista.cpp
        src/vista/MenuJuegoVista.h
        src/vista/TextoSDL.cpp
        src/vista/TextoSDL.h
        src/controlador/CartelControlador.cpp
        src/controlador/CartelControlador.h
        src/modelo/Cartel.cpp
        src/modelo/Cartel.h
        src/vista/CartelVista.cpp
        src/vista/CartelVista.h
        src/tools/Timestamp.cpp
        src/tools/Timestamp.h
        src/tools/Log.cpp
        src/tools/Log.h
        src/tools/CargadorDeConfiguracion.cpp
        src/tools/CargadorDeConfiguracion.h
        src/hilos/Hilo.h
        src/hilos/ColaProtegida.h 
        src/hilos/HiloRecibir.cpp
        src/hilos/HiloRecibir.h
        src/hilos/HiloEnviar.cpp
        src/hilos/HiloEnviar.h
        src/vista/PersonajeVista.cpp
        src/vista/PersonajeVista.h
        src/vista/EnemigoVista.cpp
        src/vista/EnemigoVista.h
        src/vista/NivelVista.h
        src/vista/NivelVista.cpp
        src/vista/CargadorTexturasEnemigos.h
        src/vista/CargadorTexturasEnemigos.cpp
        src/vista/FondoVista.cpp
        src/vista/FondoVista.h
        src/tools/ParserEstadoJuego.cpp
        src/tools/ParserEstadoJuego.h src/tools/Utils.cpp src/tools/Utils.h src/vista/CargadorTexturasPersonajes.cpp src/vista/CargadorTexturasPersonajes.h src/controlador/MenuLogControlador.cpp src/controlador/MenuLogControlador.h src/modelo/MenuLog.cpp src/modelo/MenuLog.h src/vista/MenuLogVista.cpp src/vista/MenuLogVista.h src/hilos/HiloDibujador.cpp src/hilos/HiloDibujador.h)

target_link_libraries(Cliente SDL2 SDL2_image SDL2_ttf SDL2_mixer jsoncpp pthread)
