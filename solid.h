#pragma once
#include<algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>

class Vertex
{
public:
    double x, y, z;

    void read_vertex(double a, double b, double c)
    {
        x = a;
        y = b;
        z = c;
    }
};

class Normal
{
public:
    double i, j, k;

    void read_normals(double a, double b, double c)
    {
        i = a;
        j = b;
        k = c;
    }
};

class Face
{
public:
    std::vector<Vertex> vertices;
    Normal face_normals;
};

class Obj_reader
{
public:
    std::vector<Face> faces_of_triangles;

    void read_obj_file();  //function to read input obj file
    void print_file();  // function to write into output stl file
};