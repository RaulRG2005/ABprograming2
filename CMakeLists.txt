cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(ABprograming2)

# Especificar la versión de C++
set(CMAKE_CXX_STANDARD 17)

# Agregar los archivos fuente del proyecto
add_executable(CMakeProject3
    main.cpp
    medico.cpp
    paciente.cpp
    citamedica.cpp
)
