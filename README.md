[![Build Status](https://travis-ci.com/graphprocessing/graph_coarsening.svg?branch=master)](https://travis-ci.com/graphprocessing/graph_coarsening)
[![Build status](https://ci.appveyor.com/api/projects/status/tga4d05gv8xewoab/branch/master?svg=true)](https://ci.appveyor.com/project/allnes/graph-coarsening/branch/master)

# ITLab 2018
## <b><i>Тема</i></b>: Огрубление графов

### Обозначение модулей:

| **Модуль**     | **Обозначение**                                                        |
|----------------|------------------------------------------------------------------------|
| algorithms     | Модуль основных алгоритмов (matching, partition, ... )                 |
| samples        | Модуль примеров использования проекта                                  |
| common         | Модуль функций общего назначения                                       |
| data_structure | Модуль структур данных (в том числе структур хранения графов)          |
| generators     | Модуль алгоритмов генерации графов определенной структуры              |
| tests          | Модуль google tests                                                    |
| benchmark      | Модуль google benchmark                                                |
| pipelines      | Модуль примеров использования тестовых пайплайнов                      |

### Инструкция по сборке и запуску

Note:
- для сборки необходим интерпретатор `Python 3.x`  
  Linux (Debian): `sudo apt install python3`  
  Windows: https://www.python.org/downloads/  
- для построения компилятором clang нужно установить следующую библиотеку:  
  Linux (Debian): `sudo apt-get install libiomp-dev`  
- Необходимые библиотеки для python: (установка pip : `sudo apt install python3-pip`)  
  Если Python 3.x используется по умолчанию, то используется pip вместо pip3  
  - проверка стиля кодирования:  
  `pip3 install cpplint`  
  - построение графиков асимптотики:  
  `pip3 install matplotlib`  
  - создание таблиц:  
  `pip3 install xlwt`  
  - визуализация графика:  
  `pip3 install networkx`  
  `pip3 install scipy`
- для использования статического анализатора:  
  Linux (Debian): `sudo apt install cppcheck`  
  Windows:
  1. Скачать и установить с официального сайта: http://cppcheck.sourceforge.net/
  2. Прописать путь до cppcheck в PATH

  macOS: `brew install cppcheck`  

Для Linux (Debian):
`python3 build.py <команда>`  
Для Windows:
`python build.py <команда>`  


| Описание                                  | Команда                               |
|-------------------------------------------|---------------------------------------|
| Проверка стиля кодирования                | `lint`                                |
| Построение библиотеки                     | `build <компилятор>`                  |
| Запуск модульного тестирования            | `test <компилятор>`                   |
| Запуск тестов на производительность       | `benchmark <компилятор>`              |
| Запуск lint, build, benchmark, test       | `all <компилятор>`                    |
| Построить графики асимптотики             | `asymp <компилятор> <аргументы>`      |
| Запустить пайплайны                       | `pipelines <компилятор>`              |

Примечание: по умолчанию используется компилятор g++

### Материалы:
* Ссылка на [Google drive](https://drive.google.com/drive/folders/1tVuATbCl1Kc5TMwlbntEZXAiG7QLDulV?usp=sharing)
