[![pipeline status](https://gitlab.com/allnes/graph_partition/badges/master/pipeline.svg)](https://gitlab.com/allnes/graph_partition/commits/master)

# ITLab 2018
## <b><i>Тема</i></b>: Огрубление графов
### Студенты:
1) Девликамов Владислав

2) Оболенский Арсений

3) Шрамек Максим

4) Лебедев Александр

### Обозначение модулей:

| **Модуль**     | **Обозначение**                                                          |
|----------------|--------------------------------------------------------------------------|
| algorithms     | Модуль основных алгоритмов (bfs, dfs, dijkstra, matching, partition ...) |
| application    | Модуль запуска проекта (main.cpp)                                        |
| common         | Модуль функций общего назначения (чтение/запись файла ...)               |
| data_structure | Модуль структур данных (в том числе структур хранения графов)            |
| generators     | Модуль алгоритмов генерации графов определнной структуры                 |
| tests          | Модуль google tests                                                      |

### Инструкция по сборке

```
mkdir build
cd build
cmake ..
msbuild ALL_BUILD.vcxproj   or   make -j4
tests\Test_Target.exe   or   ./tests/Test_Target
modules\application\Graph_Partition.exe   or   ./modules/application/Graph_Partition
```

### Материалы:
* Ссылка на [Google drive](https://drive.google.com/drive/folders/1tVuATbCl1Kc5TMwlbntEZXAiG7QLDulV?usp=sharing)
