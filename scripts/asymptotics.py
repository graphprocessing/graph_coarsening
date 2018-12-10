from matplotlib import pyplot as plt
from datetime import datetime
import math, sys

system_time = str(datetime.now())
begin_index = 0
png_scale = 4
scale = 100
fig = plt.gcf()
fig.set_size_inches(fig.get_size_inches()[0] * png_scale, fig.get_size_inches()[1] * png_scale)

class asymptotics_function:
    def constant(n):
        """1"""
        return 1

    def linear(n):
        """n"""
        return n

    def nlogn(n):
        """n*log(n)"""
        return n * math.log(n)

    def quadratic(n):
        """n^2"""
        return n * n

def build_graph(function):
    plt.clf()
    vertexes_beg = vertexes_end = -1
    edges_beg = edges_end = -1
    numbers_beg = numbers_end = -1
    x = []
    y = []
    f = open(file)
    for index, line in enumerate(f):
        if index < begin_index:
            continue
        line = line.split()
        number, vertexes, edges = [int(line[i]) for i in range(3)]
        time = float(line[3])
        if numbers_beg == -1:
            numbers_beg = number
        if vertexes_beg == -1:
            vertexes_beg = vertexes
        if edges_beg == -1:
            edges_beg = edges
        vertexes_end = vertexes
        edges_end = edges
        numbers_end = number
        x.append(edges)
        y.append(time / function(edges))
    plt.title(file + ", numbers=" + str(numbers_beg) + ".." + str(numbers_end) + 
                ", vertexes=" + str(vertexes_beg) + ".." + str(vertexes_end) +
                ", made at " + system_time, size=14)
    plt.xlabel("edges")
    plt.ylabel("f(execution_time)")
    plt.plot(x, y, color="tab:red", linestyle="-", label="O(" + function.__doc__ + ")")
    plt.legend(loc="upper left")
    plt.savefig(prefix_name + "_" + function.__name__ + ".png", format="png")
    f.close()

if __name__ == "__main__":
    global file, prefix_name
    if len(sys.argv) < 2:
        exit(1)
    file = sys.argv[1]
    if len(sys.argv) > 2:
        begin_index = int(sys.argv[2])
    prefix_name = sys.argv[3] if len(sys.argv) > 3 else system_time
    # Command line arguments format: <script> <data_file> <begin_index = 0> <prefix_name = system_time>
    # File format: <number> <vertexes> <edges> <time>
    build_graph(asymptotics_function.linear)
    build_graph(asymptotics_function.nlogn)
    build_graph(asymptotics_function.quadratic)