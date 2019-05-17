import sys
import matplotlib.pyplot as plt
from datetime import datetime

file = sys.argv[1]
system_time = datetime.now().strftime("%Y-%m-%d %H-%M-%S")

if __name__ == "__main__":
    f = open(file)
    x = []
    num_bins = 500
    for index, line in enumerate(f):
        data = line.split()
        if len(data) == 0:
            continue
        x.append(float(data[-1]))
        if (index < 50):
            print(float(data[-1]))
    plt.hist(x, bins=num_bins)
    print("min: ", min(*x))
    print("max: ", max(*x))
    plt.savefig(system_time + "_graph.png", format="png", dpi=500)
