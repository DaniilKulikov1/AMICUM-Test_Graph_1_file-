#include<iostream>
#include<fstream>
#define n 7
#define big 18

using namespace std;

class Graph
{
private:
    int Count; //cчётчик вершин
    int matrix[n][n];//матрица смежностей 
    int vertex[n];// матрица вершин
    
public:
    int dist[n][n]; //матрица расстояний
    
    Graph() :Count(0)
    {//счётчик обозначили нулём
        for (int i = 0; i < n; i++)
        {
            vertex[i] = -1; //отсутствие вершин -1
            for (int j = 0; j < n; ++j)
            {
                matrix[i][j] = 0; //все смежности равны 0, т.к. рёбер нет.
            }
        }
    
    }
    void Dist()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
                else if (matrix[i][j] == 1)
                {
                    dist[i][j] = 1;
                }
                else
                {
                    dist[i][j] = big;
                }
            }

        }
    
    }
    void Print();
    void addVertex(int v);
    void addEdges(int v1, int v2);
    void Floid();
};

void Graph::Floid()
{
    for (int A = 0; A < n; ++A)
    {
        for (int B = 0; B < n; ++B)
        {
            for (int C = 0; C < n; ++C)
            {
                if ((dist[A][B] + dist[B][C]) < dist[A][C])
                {
                    dist[A][C] = dist[A][B] + dist[B][C];
                }
            }
        }
    }


}

void Graph::addEdges(int v1, int v2)
{
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
    Dist();
}


void Graph::addVertex(int v)
{
    if (Count < n)
    {
        vertex[Count] = v;
        ++Count;
    }
    else if (Count < (n - 1))
    {
        vertex[n - 1] = v;
    }
    else
    {
        cout << "Места нет" << endl;
    }

}


void Graph::Print()
{
    cout << "Count: " << Count << endl;
    cout << "vertex: ";
    for (int i = 0; i < Count; ++i)
    {
        cout << vertex[i] << " ";
    }

    cout << endl;
    cout << "matrix: ";

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }

    }

    cout << endl;
    cout << "dist :";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << dist [i] [j] << " ";
        }

    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    Graph F;

    F.addVertex(1);
    F.addVertex(2);
    F.addVertex(3);
    F.addVertex(4);
    F.addVertex(5);
    F.addVertex(6);

    //соединения точки 2 с другими точкам
    F.addEdges(1,2); // 2 соединено с 1
    F.addEdges(2,3); // 2 соединено с 3
    F.addEdges(2,4); // 2 соединено с 4
    F.addEdges(2,6); // 2 соединено с 6


    F.addEdges(3,4); // 3 соединено с 4
    F.addEdges(3,5); // 3 соединено с 5
    
    F.addEdges(4, 5); // 4 соединено с 5
    F.addEdges(4, 6); // 4 соединено с 6
    
    F.addEdges(5, 6); // 5 cоединено с 6

    F.Floid();

    cout << "Минимальная дистанция от 1 до 6: " << F.dist[1][6] << endl;
    cout << "Расстояние вычислено, сейчас я создам файл Otvet.txt в той же папке," << endl;
    cout << "где и программа и запишу туда эту минимальную дистанцию " << endl;
    cout << "файл создастся после компиляции програмы" << endl;

    cout << endl;
    cout << endl;

    ofstream Otvet("Otvet.txt");

    if (Otvet.is_open())
    {
        Otvet << "Short distance 1-6: " << F.dist[1][6] << endl;
        Otvet << "Короткая дистанция между точками 1-6: " <<F.dist[1][6]<<endl;
        Otvet << endl;
        Otvet << endl;
        Otvet << "C уважением Даниил Куликов" << endl;
        Otvet << "89236349458" << endl;
    }
    else
    {
        cout << "File not open" << endl;
        cout << "Файл не открыт" << endl;
    }


    return 0;
}
