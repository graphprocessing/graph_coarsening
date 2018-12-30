[![pipeline status](https://gitlab.com/allnes/graph_partition/badges/master/pipeline.svg)](https://gitlab.com/allnes/graph_partition/commits/master)
[ ![Codeship Status for allnes/graph_partition](https://app.codeship.com/projects/b835dd10-d719-0136-841e-264e52b87e69/status?branch=master)](https://app.codeship.com/projects/317102)

# ITLab 2018
## <b><i>Тема</i></b>: Огрубление графов

### Обозначение модулей:

| **Модуль**     | **Обозначение**                                                          |
|----------------|--------------------------------------------------------------------------|
| algorithms     | Модуль основных алгоритмов (bfs, dfs, dijkstra, matching, partition ...) |
| application    | Модуль запуска проекта (main.cpp)                                        |
| common         | Модуль функций общего назначения (чтение/запись файла ...)               |
| data_structure | Модуль структур данных (в том числе структур хранения графов)            |
| generators     | Модуль алгоритмов генерации графов определенной структуры                |
| tests          | Модуль google tests                                                      |
| benchmark      | Модуль google benchmark                                                  |
| pipelines      | Модуль самописных тестовых пайплайнов                                    |

### Инструкция по сборке и запуску

Note:
- для сборки необходим интерпретатор `Python 3.x`  
  Linux: `sudo apt install python3`  
  Windows: https://www.python.org/  
- для построения компилятором clang нужно установить следующую библиотеку:  
  Linux: `sudo apt-get install libiomp-dev`  
- Необходимые библиотеки для python: (установка pip : `sudo apt install python3-pip`)  
  Для Windows используется pip вместо pip3  
  - проверка стиля кодирования:  
  `pip3 install cpplint`  
  - построение графиков асимптотики:  
  `pip3 install matplotlib`  
  - создание таблиц:
  `pip3 install xlwt`
- для использования статического анализатора:  
  Linux: `sudo apt install cppcheck`  
  Windows:  
  1) Скачать и установить с официального сайта: http://cppcheck.sourceforge.net/  
  2) Прописать путь до cppcheck в PATH  
  macOS: `brew install cppcheck`  

Для Linux:
`python3 build.py <команда>`  
Для Windows:
`python build.py <команда>`  


| Описание                                  | Команда                               |
|-------------------------------------------|---------------------------------------|
| Проверка стиля кодирования                | `lint`                                |
| Построение библиотеки                     | `build <компилятор>`                  |
| Запуск модульного тестирования            | `test <компилятор>`                   |
| Запуск тестов на производительность       | `benchmark <компилятор>`              |
| Запуск main()                             | `run <компилятор>`                    |
| Запуск lint, build, benchmark, test, run  | `all <компилятор>`                    |
| Построить графики асимптотики             | `asymp <компилятор> <аргументы>`      |
| Запустить пайплайны                       | `pipelines <компилятор>`              |

### Материалы:
* Ссылка на [Google drive](https://drive.google.com/drive/folders/1tVuATbCl1Kc5TMwlbntEZXAiG7QLDulV?usp=sharing)
