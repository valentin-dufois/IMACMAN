cmake_minimum_required(VERSION 3.9)
project(IMACMAN)

set(CMAKE_CXX_STANDARD 11)

add_executable(IMACMAN
        .idea/IMACMAN.iml
        .idea/modules.xml
        .idea/workspace.xml
        IMACMAN/.vs/ProjectSettings.json
        IMACMAN/.vs/slnx.sqlite
        IMACMAN/.vs/VSWorkspaceState.json
        IMACMAN/Core/Core.cpp
        IMACMAN/Core/Core.hpp
        IMACMAN/Core/GameObject.cpp
        IMACMAN/Core/GameObject.hpp
        IMACMAN/Core/Igniter.cpp
        IMACMAN/Core/Igniter.hpp
        IMACMAN/Engines/RessourcesEngine/Elements/Asset.hpp
        IMACMAN/Engines/RessourcesEngine/Elements/Image.cpp
        IMACMAN/Engines/RessourcesEngine/Elements/Image.hpp
        IMACMAN/Engines/RessourcesEngine/Elements/Level.cpp
        IMACMAN/Engines/RessourcesEngine/Elements/Level.hpp
        IMACMAN/Engines/RessourcesEngine/Elements/Mesh.cpp
        IMACMAN/Engines/RessourcesEngine/Elements/Mesh.hpp
        IMACMAN/Engines/RessourcesEngine/Elements/Shader.cpp
        IMACMAN/Engines/RessourcesEngine/Elements/Shader.hpp
        IMACMAN/Engines/RessourcesEngine/Elements/Sound.cpp
        IMACMAN/Engines/RessourcesEngine/Elements/Sound.hpp
        IMACMAN/Engines/RessourcesEngine/Importers/ImageImporter.cpp
        IMACMAN/Engines/RessourcesEngine/Importers/ImageImporter.hpp
        IMACMAN/Engines/RessourcesEngine/Importers/Importer.hpp
        IMACMAN/Engines/RessourcesEngine/Importers/LevelImporter.cpp
        IMACMAN/Engines/RessourcesEngine/Importers/LevelImporter.hpp
        IMACMAN/Engines/RessourcesEngine/Importers/MeshImporter.cpp
        IMACMAN/Engines/RessourcesEngine/Importers/MeshImporter.hpp
        IMACMAN/Engines/RessourcesEngine/Importers/ShaderImporter.cpp
        IMACMAN/Engines/RessourcesEngine/Importers/ShaderImporter.hpp
        IMACMAN/Engines/RessourcesEngine/Importers/SoundImporter.cpp
        IMACMAN/Engines/RessourcesEngine/Importers/SoundImporter.hpp
        IMACMAN/Engines/RessourcesEngine/RessourcesEngine.cpp
        IMACMAN/Engines/RessourcesEngine/RessourcesEngine.hpp
        IMACMAN/main.cpp
        IMACMAN/main.hpp
        IMACMAN/main.o
        IMACMAN/makefile
        .gitignore
        README.md)
