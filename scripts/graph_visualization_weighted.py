from graphviz import Digraph, Source, render
from datetime import datetime
import sys

file = sys.argv[1]
system_time = datetime.now().strftime("%Y-%m-%d %H-%M-%S")

if __name__ == "__main__":
    for eng in ("dot", "neato", "twopi", "circo", "fdp", "sfdp"):
        dot = Digraph(comment=system_time + '_' + eng)
        f = open(file, "r")
        graph = []
        used = []
        for index, line in enumerate(f):
            data = line.split()
            if len(data) == 0:
                continue
            if data[1] < data[0]:
                data[0], data[1] = data[1], data[0]
            if (data[0], data[1]) not in used:
                data = (data[0], data[1], data[2])
                used.append((data[0], data[1]))
                graph.append(data)
        f.close()
        for data in graph:
            dot.edge(data[0], data[1], weight=data[2], label=data[2], color="black",
                        arrowhead="none", arrowtail="none")
        src = Source(dot.source)
        filename = system_time + '_' + eng + '.gv'
        src.render(filename)
        render(eng, 'svg', filename)