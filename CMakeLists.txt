#pour supprimer tout dans le build et recompiler rm -rf build
cmake_minimum_required(VERSION 2.22.1)
project(module-image)

set(CMAKE_CXX_STANDARD 17)
set(EXAMPLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(TEST_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(AFFICHAGE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#pour trouver sdl
find_package(SDL2 CONFIG REQUIRED)
#find_package(SDL2_image CONFIG REQUIRED)
#find_package(SDL2_mixer CONFIG REQUIRED)
#find_package(SDL2_ttf CONFIG REQUIRED)



add_executable(test src/mainTest.cpp
        src/Image.h
        src/Pixel.h
        src/Image.cpp
        src/Pixel.cpp
)
add_executable(exemple src/mainExemple.cpp
        src/Image.h
        src/Image.cpp
        src/Pixel.h
        src/Pixel.cpp
)
add_executable(affichage src/mainAffichage.cpp
        src/ImageViewer.h
        src/ImageViewer.cpp
        src/Image.h
        src/Image.cpp
        src/Pixel.h
        src/Pixel.cpp
)

# Définition du chemin de sortie pour l'exécutable exemple
set_target_properties(exemple PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${EXAMPLE_OUTPUT_PATH}
)

set_target_properties(test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_PATH}
)

set_target_properties(affichage PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${AFFICHAGE_OUTPUT_PATH}
)


# Inclusion des en-têtes des bibliothèques
target_include_directories(affichage PRIVATE
        ${SDL2_INCLUDE_DIRS}
        "/usr/include/SDL2"
        #        ${SDL2_MIXER_INCLUDE_DIRS}
        #        ${SDL2_TTF_INCLUDE_DIRS}
)

# edition liens
target_link_libraries(affichage PRIVATE
        SDL2
        SDL2_image
)



