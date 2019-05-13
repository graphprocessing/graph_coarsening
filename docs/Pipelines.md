## What are pipelines ##
Pipelines describe sequence of actions that you want to automate such as reading from file, writing to file, coarsening, characteristics evaluation and so on.

## How to use pipelines ##

In order to run pipeline, you need to create file in .yaml format. This sequence should obey some rules.

First of all, you need to specify the name of pipeline followed by colon:

```yaml
my_pipeline:
```

Note: you can define multiple pipelines in one file.

After that you can write combination of supported functions (cf. Functions section). Each function should be written after two spaces and dash. Parameters of the function should not have dash.

```yaml
my_pipeline:
  - graph_generate: washington_test
  - graph_output: graph.bin
```

Pipelines functions become available when you include `modules/pch/precomp.h` file.

Class 'PipelineParser' provides pipelines interface. First of all you need to construct PipelineParser object. In order to do that you need to send file name as `const std::string &`.
```cpp
PipelineParser pipeline("file.yaml");
```
After that you should launch this by calling this function.
```cpp
pipeline.launch();
```

## Functions ##
* input
  ```yaml
  input: file_name
  ```
  Reads CSR graph from binary file 'file_name'
* graph_generate
  ```yaml
  graph_generate: generator_name
  n: number
  m: number
  ```
  Generates graph of the following type. `n`, `m` are specific to each generator values (not always required)
* coarsening
  ```yaml
  coarsening: coarsening_type
  ```
  Does graph coarsening.
  Types of coarsening:
  1. matching:  
     random, hard, edmonds
  
  Count (optional): how many times you want to perform coarsening, default = 1.  
  Example:
  ```yaml
  coarsening: matching
  type: random
  count: 10
  ```
* evaluate
  ```yaml
  evaluate: characteristic
  ```
  Evaluates the following characteristic for the table described in `scripts/pipelines_table.py`  
  Warning: All functions in pipeline are processing one by one, so this function will evaluate characteristic when it is called.  
  List of characteristics:  
  1. `pipeline_time` - time (starting from PipelineParser constructor call)
  1. `vertexes` - number of vertexes in graph
  1. `edges` - number of edges in graph
  1. `avg_vertex_degree` - average degree of vertexes
  1. `max_vertex_weight` - maximal vertex weight
  1. `graph_diameter` - graph diameter
  1. `graph_radius` - graph radius
  1. `vertexes_in_scc` - average number of vertexes in strongly connected components
  1. `bridges` - number of bridges in graph
  1. `joint_points` - number of joint points in graph
  1. `avg_eccentricity` - average vertexes eccentricity
  1. `cost_mst` - sum of edges cost in minimal spanning tree
* graph_output
  ```yaml
  graph_output: file_name
  ```
  Writes CSR graph to binary file 'file_name'
* table_output
  ```yaml
  table_output: file_name
  ```
  Attributes:
  * append: 0 - false, 1 - true. If you want to append new result without erasing previous ones, you should choose 1, 0 overwise.

  Creates table with configuration described in `scripts/pipelines_table.py`  
  Note: Before export itself you need to calculate characteristics (cf. evaluate function)
* convert
  ```yaml
  convert: convert_type
  ```
  Performs graph conversion.  
  List of conversions:
  1. `undirected` - converts this graph to undirected one
  1. `unweighted` - converts this graph to unweighted one
* graph_export_edges
  ```yaml
  graph_export_edges: file_name
  ```
  Exports info about graph edges in the following format:
  ```
  <edge1_begin> <edge1_end> <edge1_weight>
  <edge2_begin> <edge2_end> <edge2_weight>
  ...
  <edgen_begin> <edgen_end> <edgen_weight>
  ```
  This option may be useful for, for example, graph visualization.

## Pipeline sample ##

```yaml
sample_pipeline:
  - graph_generate: cube_test
    n: 25
    weighted: 1
  - graph_export_edges: ../graph_data/cube_01.txt
  - coarsening: matching
    type: random
    count: 5
  - coarsening: matching
    type: hard
    count: 5
  - evaluate: pipeline_time
  - evaluate: vertexes
  - evaluate: edges
  - graph_output: ../graph_data/cube_test_compressed.bin
  - table_output: ../graph_data/table.txt
    append: 0
  - graph_export_edges: ../graph_data/cube_02.txt
```