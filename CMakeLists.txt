cmake_minimum_required(VERSION 3.10)	 

project(algo_lib)

add_library(${PROJECT_NAME} STATIC
    include/algo_lib/edge/edge.h
    include/algo_lib/constants.h 
    include/algo_lib/graph/graph.cpp
    include/algo_lib/algorithms/bfs.cpp 
    include/algo_lib/algorithms/articulation_points.cpp 
    include/algo_lib/algorithms/bridges.cpp 
    include/algo_lib/algorithms/dfs.cpp
    include/algo_lib/algorithms/fast_dijkstra.cpp 
    include/algo_lib/algorithms/floyd.cpp 
    include/algo_lib/algorithms/ford_bellman.cpp 
    include/algo_lib/algorithms/slow_dijkstra.cpp 
    include/algo_lib/algorithms/binpow.h 
    include/algo_lib/algorithms/gcd.h 
    include/algo_lib/algorithms/gcd_ext.h 
    include/algo_lib/algorithms/num_by_permutation.cpp
    include/algo_lib/algorithms/permutation_by_num.cpp 
    include/algo_lib/algorithms/segtree.cpp 
    include/algo_lib/algorithms/geometry.cpp 
    include/algo_lib/algorithms/hash.h 
    include/algo_lib/algo.h
)

target_include_directories(${PROJECT_NAME} PUBLIC include)