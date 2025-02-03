# Algo_lib
Algo_lib - библиотека, содержащая в себе реализации популярных алгоритмов и структур данных.

# Документация
## Как подключить библиотеку
1. Скачать этот репозиторий (папку algo_lib)
2. В Cmake файле добавить команды ```add_subdirectory(.../path/to/algo_lib algo_lib)``` и ```target_link_libraries(... algo_lib)```
3. В программе написать ```#include "algo_lib/algo.h"```

## Как пользоваться библиотекой
- ### ```edge``` - ребро графа
    - ```edge()``` - пустой конструктор, присваивает обоим вершинам ребра номер $-\infty$ и вес $0$   
    - ```edge(int vertex1, int vertex2)``` - присваивает вершинам ребра номера vertex1 и vertex2 соответственно, а вес равный $0$
    - ```edge(int vertex1, int vertex2, int weight)``` - присваивает вершинам ребра номера vertex1 и vertex2 соответственно, а вес равный weight
    - ```edge& operator = (const edge& edge)``` - присваивает ребру вершины и вес другого ребра
    - ```bool operator == (const edge& edge)``` - проверка равенства ребер по их вершинам и весам
    - ```bool operator < (const edge& edge)```, ```bool operator > (const edge& edge)``` - сравнение ребер по их весам
    - ```void set_vertexes(int vertex1, int vertex2)``` - присваивает вершинам ребра значения vertex1 и vertex2 соответственно 
    - ```std::pair<int, int> getVertexes()``` - возвращает пару из значений ```{vertex1, vertex2}```
    - ```void set_weight(int weight)``` - присваивает ребру вес, равный weight
    - ```int get_weight()``` - возвращает вес ребра
- ### graph - граф
    - ```graph()``` - пустой конструктор
    - ```graph(std::vector<edge> edges)``` - присваивает списку ребер значение edges, граф - неориентированный
    - ```graph(std::vector<edge> edges, bool isDirected)``` - присваивает списку ребер значение edges, а неориентированность/ориентированность графа задается переменной isDirected
    - ```void addEdge(edge edge)``` - добавить в граф ребро edge
    - ```void removeEdge(edge edge)``` - удалить из графа ребро edge
    - ```std::vector<edge> getEdges()``` - возвращает список ребер графа
    - ```void setEdges(std::vector<edge> edges)``` - присваивает списку ребер графа значение edges
    - ```std::vector<std::vector<std::pair<int,int>>> getMatrix()``` - возвращает матрицу смежности графа
    - ```void setDirected(bool val)``` - присваивает переменной isDirected значение val
    - ```bool getDirected()``` - возвращает значение переменной isDirected
- ### std::vector<int> articulation_points(graph g)
    - Возвращает номера вершин, которые являются точками сочленения в графе g 
- ### std::vector<int> bfs(graph g, int startVertexNumber)
    - Обход графа g в ширину. Возвращает расстояния от вершины startVertexNumber до вершин 0, 1, ... , n-1 соответственно
- ### T binpow(T a, T n, T mod)
    - Бинарное возведение числа a в степень n по модулю mod
- ### std::vector<edge> bridges(graph g)
    - Возвращает список ребер, являющихся мостами в графе g
- ### std::vector<int> dfs(graph g, int startVertex)
    - Обход графа g в глубину. Возвращает топологически отсортированный список вершин
- ### std::vector<int> fast_dijkstra(graph g, int startVertex)
    - Реализация "быстрого" алгоритма Дейкстры $(O(m\log n))$. Возвращает расстояния от вершины startVertex до вершин 0, 1, ... , n-1 соответственно
- ### std::vector<std::vector<int>> floyd(graph g)
    - Реализация алгоритма Флойда - Уоршелла. Возвращает матрицу кратчайших путей между вершинами
- ### std::vector<int> ford_bellman(graph g, int startVertex)
    - Реализация алгоритма Форда - Беллмана. Возвращает расстояния от вершины startVertex до вершин 0, 1, ... , n-1 соответственно
- ### T gcd_ext(T a, T b, T &x, T &y)
    - Расширенный алгоритм Евклида. Решает уравнение вида $ax + by = gcd(a, b)$
- ### T gcd(T a, T b)
    - Алгоритм Евклида. Находим НОД чисел a и b
- ### geometry - работа с геометрией
    - ```struct point``` - структура точки (или же, вектора)
        - x, y - координаты точки (вектора)
        - ```point()``` - пустой конструктор
        - ```point(double x, double y)``` - присваивание переменным x и y соответствующих им значений
    - ```std::istream& operator >> (std::istream& is, point& a)```, ```std::ostream& operator << (std::ostream& os, const point& a)``` - переопределение операторов ввода и вывода для point
    - ```point operator + (point& a, point& b)``` - оператор сложение point
    - ```point operator - (point& a, point& b)``` - оператор вычитания point
    - ```double vector_product(const point& a, const point& b)``` - вектороное произведение векторов a и b
    - ```double scalar_product(const point& a, const point& b)``` - скалярное произведение векторов a и b
    - ```double len(const point& a)``` - возвращает длину(модуль) вектора a
    - ```double triangle_square(const point& a, const point& b)``` - возвращает площадь треугольника, заданного векторами a и b
    - ```double get_angle(const point& a, const point& b)``` - возвращает угол между векторами a и b
    - ```bool equal(const double& a, const double& b)``` - проверка векторов a и b на равенство
    - ```bool compare_points_by_coords(const point& a, const point& b)``` - сравнение векторов по координатам
    - ```bool compare_points_by_vector_product(point& a, point& b)``` - сравнение векторов по векторному произведению
    - ```std::vector<point> convex_hull(std::vector<point> p)``` - построение выпуклой оболочки для заданных точек
- ### Hash - хэши
    - ```Hash(const std::string& s, const long long p = 239017)``` - конструктор, принимаюий в себя строку, с которой будет работать класс, и простое число p
    - ```long long getHash(int l, int r)``` - возвращает хэш подстроки с l по r включительно
- ### long long num_by_permutation(std::vector<int> a) 
    - Возвращает номер по перестановке a
- ### std::vector<int> permutation_by_num(int num, int len)
    - Возвращает перестановку длины len по номеру num
- ### segtree - дерево отрезков
    - ```segtree(std::vector<int> a)``` - конструктор дерева отрезков на массиве a
    - ```void set(int x, int lx, int rx, int l, int r, int val)``` - присваивание на полуинтервале $[l, r)$ значения val. По умолчанию, задать x = 0, lx = 0, rx = a.size()
    - ```void add(int x, int lx, int rx, int l, int r, int val)``` - прибавление на полуинтервале $[l, r)$ значения val. По умолчанию, задать x = 0, lx = 0, rx = a.size()
    - ```node ask(int x, int lx, int rx, int l, int r)``` - получить ответ на полуинтервале $[l, r)$. Возвращается node, содержащая в себе поля sum(сумма на полуинтервале), min(минимум на полуинтервале), max(максимум на полуинтервале). По умолчанию, задать x = 0, lx = 0, rx = a.size()
- ### std::vector<int> slow_dijkstra(graph g, int startVertex)
    - Реализация "медленного" алгоритма Дейкстры $(O(n^2))$. Возвращает расстояния от вершины startVertex до вершин 0, 1, ... , n-1 соответственно