import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.pylab as plb
import sys

file = sys.argv[1]
png_scale = 2
fig = plt.gcf()
fig.set_size_inches(fig.get_size_inches()[0] * png_scale, fig.get_size_inches()[1] * png_scale)

if __name__ == "__main__":
    graph = nx.DiGraph()
    f = open(file, "r")
    for index, line in enumerate(f):
        data = line.split()
        graph.add_edge(data[0], data[1], weight=data[2])
    f.close()
    plt.figure()
    plt.axis("off")
    layout = nx.spring_layout(graph)
    nx.draw_networkx_nodes(graph, layout)
    nx.draw_networkx_edges(graph, layout)
    nx.draw_networkx_labels(graph, layout)
    plt.savefig("out.png", format="png")
    plb.close()
