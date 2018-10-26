# ITLab 2018
## <b><i>Тема</i></b>: Огрубление графов
### Студенты:
1) Девликамов Владислав

2) Оболенский Арсений

3) Шрамек Максим

### Обозначение модулей:

| Модуль         | Обозначение                                                              |
|----------------|--------------------------------------------------------------------------|
| algorithms     | Модуль основных алгоритмов (bfs, dfs, dijkstra, matching, partition ...) |
| application    | Модуль запуска проекта (main.cpp)                                        |
| common         | Модуль функций общего назначения (чтение/запись файла ...)               |
| data_structure | Модуль структур данных (в том числе структур хранения графов)            |
| generators     | Модуль алгоритмов генерации графов определнной структуры                 |

### Инструкция по сборке

```
mkdir build
cd build
cmake ..
msbuild ALL_BUILD.vcxproj   or   make -j4
modules\application\Graph_Partition.exe   or   ./modules/application/Graph_Partition
```

### Материалы:
* Ссылка на [Google drive](https://drive.google.com/drive/folders/1tVuATbCl1Kc5TMwlbntEZXAiG7QLDulV?usp=sharing)

### Задание (23.10.2018):

1) Реализовать хранение графов (для информации на Google drive директория storage)

    a) Adj. list

    b) CRS

    c) JDF

2) Реализовать бинарное представление больших графов

3) Реализовать определенные структуры графов (для информации на Google drive директория generator)

    a) zadeh_test

    b) washington_test

    c) grid_3d

4) Реализовать графовые алгоритмы на этих графах в этих формах хранения:

    a) bfs

    b) dfs
    
    c) dijkstra
