import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.pylab as plb
import sys
from datetime import datetime

file = sys.argv[1]
png_scale = 3
system_time = datetime.now().strftime("%Y-%m-%d %H-%M-%S")

if __name__ == "__main__":
    graph = nx.DiGraph()
    f = open(file, "r")
    for index, line in enumerate(f):
        data = line.split()
        if len(data) == 0:
            continue
        graph.add_edge(data[0], data[1], weight=data[2])
    f.close()
    fig = plt.figure(1)
    fig.set_size_inches(fig.get_size_inches()[0] * png_scale, fig.get_size_inches()[1] * png_scale)
    plt.title(system_time + " graph")
    plt.axis("off")
    pos = nx.spring_layout(graph)
    nx.draw_networkx_nodes(graph, pos)
    nx.draw_networkx_edges(graph, pos)
    weights = nx.get_edge_attributes(graph, 'weight')
    nx.draw_networkx_labels(graph, pos)
    if input("Display graph weights? (y/n)\n> ")[0].lower() == 'y':
        nx.draw_networkx_edge_labels(graph, pos, edge_labels=weights)
    plt.savefig(system_time + "_graph.png", format="png", dpi=500)
    plb.close()
