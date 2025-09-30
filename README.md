🚀 **HackerRank Solutions**

Welcome to my personal collection of HackerRank C++ practice solutions.  
This repository is designed to sharpen core C++ skills, improve algorithmic thinking, and reinforce clean code practices.

📚 **Contents**

Each folder or file in this repo corresponds to a specific HackerRank challenge.

Organized by difficulty:
- 🟢 Easy
- 🟡 Medium
- 🔴 Hard

```
📁 {Difficulty}/
    📁 {Category}/
        📁 {Problem}/
            📁 {c++ version}/
                📝 Problem.md
                📝 Solution.cpp
                📁 build/
```

> ⚠️ Note: Each problem `build/` folder is **!GENERATED!** when Solution.cpp is being compiled.

**🛠️ Compiler & IDE**

- OS: **Windows**  
- Compiler: **GCC g++.exe**  
- IDE: **VS Code**  
- Build configs: defined in `launch.json` and `tasks.json` 
> Note: Some of the problems have `CMakeLists.txt` file to build and run `Solution.cpp`

**▶️ Build & Run**

**Using MSVC**  
Select `C/C++: g++.exe` compiler and run using `f5`  
Executables are generated inside the problem’s `build/` directory.

**Using CMake**

1. go to any problem directory,  
```
    cd {any-solution-dir}
```
> Note: replace {any-solution-dir} with actual directory name

2. create build folder
```
    mkdir build
```

3. generate build configuration files using g++ compiler
```
    cmake -B build -S . -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
```

4. create executable file
```
    cmake --build build
```
5. navigate to ./build/Debug folder
```
    cd ./build
```
6. run executable by running
```
    ./{solution-name}
```
>  Note: Depending on the shell, the correct syntax may be: {solution-name}, ./{solution-name} or .\\{solution-name}