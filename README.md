# VerletSFML

This project is a naive example of a simple physics engine using the Verlet integration.
[![Alt-Text](https://i.ytimg.com/vi/lS_qeBy3aQI/maxresdefault.jpg)](https://www.youtube.com/watch?v=lS_qeBy3aQI)

# Setup SFML with Visual Studio and CMake
1. clone github repository https://github.com/SFML/SFML.git
1. Install Visual Studio with C++ and with CMake support
1. Start Visual Studio
1. Click on "Continue without code"
1. Select Visual Studio main menu "File, Open, CMake..."
1. In the file dialog window "Open CMake-project from CMakeLists.txt" navigate to the directory of your local SFML git repository C:\your_local_path_to\SFML\ and select the file CMakeLists.txt and finally click the button "Open".
1. Visual Studio is automatically analyzing the CMake project. Wait for it to finish until the Output window reports "CMake-Generation finished".
1. Select Visual Studio main menu "Build, Build All..."
1. Select Visual Studio main menu "Build, Install "SFML"...". According to file C:\your_local_path_to\SFML\CMakePresets.json the binary files will be installed in C:\your_local_path_to\SFML\build\install\. There you will find the three folders "include", "lib" and "share".

# Setup VerletSFML with Visual Studio and CMake
1. clone github repository https://github.com/martinjanfischer/VerletSFML.git (which is a fork of https://github.com/johnBuffer/VerletSFML.git)
1. Start Visual Studio
1. Click on "Continue without code"
1. Select Visual Studio main menu "File, Open, CMake..."
1. In the file dialog window "Open CMake-project from CMakeLists.txt" navigate to the directory of your local SFML git repository C:\your_local_path_to\VerletSFML\ and select the file CMakeLists.txt and finally click the button "Open".
1. Visual Studio is automatically analyzing the CMake project. Wait for it to finish until the Output window reports "CMake-Generation finished".
1. If necessary, select Visual Studio main menu "Project, CMakeSettings for "Verlet" "
1. Select Visual Studio main menu "Build, Build All..."
1. Select Visual Studio main menu "Debug, Start Debugging..." or  "Debug, Start without Debugging...".