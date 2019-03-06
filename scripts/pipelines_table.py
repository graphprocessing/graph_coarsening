import xlwt, sys, os

input_file = sys.argv[1]
output_file = sys.argv[2]

if __name__ == "__main__":
    book = xlwt.Workbook()
    sheet = book.add_sheet("List 1")
    sheet.col(0).width = 15000
    sheet.write(0, 0, "Название пайплайна")
    sheet.write(1, 0, "Время работы всего сжатия")
    sheet.write(2, 0, "Количество ребер")
    sheet.write(3, 0, "Количество вершин")
    sheet.write(4, 0, "Средняя степень вершины")
    sheet.write(5, 0, "Максимальный вес вершины")
    sheet.write(6, 0, "Диаметр графа")
    sheet.write(7, 0, "Радиус графа")
    sheet.write(8, 0, "Cреднее число вершин в компоненте сильной связности")
    sheet.write(9, 0, "Количество мостов")
    sheet.write(10, 0, "Количество точек сочленения")
    sheet.write(11, 0, "Средний эксцентриситет вершины")
    sheet.write(12, 0, "Суммарный вес ребер в минимальном остовном дереве")
    file = open(input_file, "r")
    for index, line in enumerate(file):
        sheet.col(index + 1).width = 10000
        data = line.split()
        for i in range(len(data)):
            sheet.write(i, index + 1, data[i])
    file.close()
    book.save(output_file)