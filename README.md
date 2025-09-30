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
            📝 Problem.md
            📝 Solution.cpp
```

**🛠️ Compiler & IDE**

- OS: **Windows**  
- Compiler: **GCC g++.exe**  
- IDE: **VS Code**  
- Build system: **CMake** 

**▶️ Build & Run**  
> Note: Each problem have `CMakeLists.txt` file under its directory

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