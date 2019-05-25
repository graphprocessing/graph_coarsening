## Graph coarsening library

### Modules description:

| **Module** | **Description** |
|-----------------|------------------------------------------------------|
| algorithms      | Algorithms module (matching, partition, ... ) |
| samples         | Project use cases |
| common          | General purpose functions module |
| data_structures | Data structures module |
| generators      | Graph structure generators module |
| tests           | Google test module |
| benchmark       | Google benchmark module |
| pipelines       | Pipelines module (cf. Pipelines.md) |

### Build and run instructions

Note:
- `Python 3.x` interpreter is necessary for build  
  Linux (Debian): `sudo apt install python3`  
  Windows: https://www.python.org/downloads/  
- For clang compiler you need to install this library:  
  Linux (Debian): `sudo apt install libiomp-dev`  
- Necessary libraries for Python: (pip installation : `sudo apt install python3-pip`)  
  If Python 3.x is default Python in your system you may use `pip` instead of `pip3` as well as `python` instead of `python3`  
  - code style checking:  
  ```
  pip3 install cpplint
  ```
  - graphics:  
  ```
  pip3 install matplotlib  
  ```
  - creation of xls table:  
  ```
  pip3 install xlwt 
  ```
  - graph visualization:  
  ```
  pip3 install graphviz
  sudo apt install graphviz
  ```
- Static analysis tool:  
  Linux (Debian): `sudo apt install cppcheck`  
  Windows:
  1. Download and setup: http://cppcheck.sourceforge.net/
  2. Add path to .exe file to system PATH variable

  macOS: `brew install cppcheck`  

For Linux (Debian):
`python3 build.py <command>`  
For Windows:
`python build.py <command>`  


| **Description** | **Command** |
| --- | -------- |
| Code style checking | `lint` |
| Library build | `build <compiler>` |
| Run unit tests | `test <compiler>` |
| Run sample | `run <compiler> <example>` |
| Run benchmark | `benchmark <compiler>` |
| Run lint, build, benchmark, test | `all <compiler>` |
| Draw asymptotic graphics | `asymp <compiler> <args>` |
| Run pipelines | `pipelines <compiler>` |

Note: the default compiler is g++

### Example default build library
```
git submodule update --init --recursive
mkdir build
cd build
cmake ..
cmake --build . --config Release -- -j2
./bin/test_target
./bin/benchmark_target
```