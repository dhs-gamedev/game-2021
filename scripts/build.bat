if not exist "build\" mkdir build\
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/
cmake --build build/
