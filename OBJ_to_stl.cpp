#include <iostream>
#include "solid.h"


void Obj_reader :: read_obj_file()
{
    std::ifstream file("obj_cube.obj"); // open file for readindg

    if (file.is_open()) // checking if file is open to read
    {
        std::string line;

        std::vector<Vertex> vertices;
        std::vector<Normal> normals;

        while (std::getline(file, line)) // for reading each line
        {
            std::istringstream in(line);
            std::vector<std::string> vec_line;

            while (in >> line)
            {
                vec_line.push_back(line);
            }

            if (vec_line[0] == "v") // storing values of normals
            {

                Vertex v_obj1; 
                v_obj1.read_vertex(stod(vec_line[1]), stod(vec_line[2]), stod(vec_line[3]));
                vertices.push_back(v_obj1); // 
            }

            else if (vec_line[0] == "vn") // storing values of normals
            {

                Normal vn_obj1;

                vn_obj1.read_normals(stod(vec_line[1]), stod(vec_line[2]), stod(vec_line[3]));
                normals.push_back(vn_obj1);
            }

            else if (vec_line[0] == "f")  //for reading files without texture (f v/t/n)
            {

               /* char slash = '/';
                int slash_count = std::count(line.begin(), line.end(), slash); // counting numbers of slash in lines

                if(slash_count == 6) 
                {

                    Face face1;
                    Vertex vert1;

                    size_t idx1 = vec_line[1].find("/");
                    unsigned int idx_fv_1 = std::stod(vec_line[1].substr(0, idx1)); 
                    size_t idx2 = vec_line[1].find("/", idx1 + 1);
                    unsigned int idx_ftc_1 = std::stod(vec_line[1].substr(idx1 + 1, idx2));
                    size_t idx7 = vec_line[1].find("/");
                    unsigned int idx_fvn_1 = std::stod(vec_line[1].substr(idx2 + 1, idx7));

                    size_t idx3 = vec_line[2].find("/");
                    unsigned int idx_fv_2 = std::stod(vec_line[2].substr(0, idx3)); 
                    size_t idx4 = vec_line[2].find("/", idx3 + 1);
                    unsigned int idx_ftc_2 = std::stod(vec_line[2].substr(idx3 + 1, idx4));
                    size_t idx8 = vec_line[2].find("/");
                    unsigned int idx_fvn_2 = std::stod(vec_line[2].substr(idx4 + 1, idx8));

                    size_t idx5 = vec_line[3].find("/");
                    unsigned int idx_fv_3 = std::stod(vec_line[3].substr(0, idx5)); 
                    size_t idx6 = vec_line[3].find("/", idx5 + 1);
                    unsigned int idx_ftc_3 = std::stod(vec_line[3].substr(idx5 + 1, idx6));
                    size_t idx9 = vec_line[3].find("/");
                    unsigned int idx_fvn_3 = std::stod(vec_line[3].substr(idx6 + 1, idx9));


                    face1.face_normals.i = normals[idx_fvn_1 - 1].i;
                    face1.face_normals.j = normals[idx_fvn_1 - 1].j;
                    face1.face_normals.k = normals[idx_fvn_1 - 1].k;

                    vert1.x = vertices[idx_fv_1 - 1].x;
                    vert1.y = vertices[idx_fv_1 - 1].y;
                    vert1.z = vertices[idx_fv_1 - 1].z;

                    face1.vertices.push_back(vert1);

                    vert1.x = vertices[idx_fv_2 - 1].x;
                    vert1.y = vertices[idx_fv_2 - 1].y;
                    vert1.z = vertices[idx_fv_2 - 1].z;

                    face1.vertices.push_back(vert1);

                    vert1.x = vertices[idx_fv_3 - 1].x;
                    vert1.y = vertices[idx_fv_3 - 1].y;
                    vert1.z = vertices[idx_fv_3 - 1].z; 

                    face1.vertices.push_back(vert1);

                    faces_of_triangles.push_back(face1);

                //}
 
               // else // for reading files with texture (f v/n)
                { */
                    Face face1;   
                    Vertex vert1;

                    size_t idx1 = vec_line[1].find("/");
                    unsigned int idx_fv_1 = std::stoi(vec_line[1].substr(0, idx1));
                    size_t idx2 = vec_line[1].find("/", idx1 + 1);
                    unsigned int idx_fvn_1 = std::stoi(vec_line[1].substr(idx1 + 1, idx2));

                    size_t idx3 = vec_line[2].find("/");
                    unsigned int idx_fv_2 = std::stoi(vec_line[2].substr(0, idx3));
                    size_t idx4 = vec_line[2].find("/", idx3 + 1);
                    unsigned int idx_fvn_2 = std::stoi(vec_line[2].substr(idx3 + 1, idx4));

                    size_t idx5 = vec_line[3].find("/");
                    unsigned int idx_fv_3 = std::stoi(vec_line[3].substr(0, idx5));
                    size_t idx6 = vec_line[3].find("/", idx5 + 1);
                    unsigned int idx_fvn_3 = std::stoi(vec_line[3].substr(idx5 + 1, idx6));

                    face1.face_normals.i = normals[idx_fvn_1 - 1].i;  
                    face1.face_normals.j = normals[idx_fvn_1 - 1].j;
                    face1.face_normals.k = normals[idx_fvn_1 - 1].k;

                    vert1.x = vertices[idx_fv_1 - 1].x;
                    vert1.y = vertices[idx_fv_1 - 1].y;
                    vert1.z = vertices[idx_fv_1 - 1].z;

                    face1.vertices.push_back(vert1);

                    vert1.x = vertices[idx_fv_2 - 1].x;
                    vert1.y = vertices[idx_fv_2 - 1].y;
                    vert1.z = vertices[idx_fv_2 - 1].z;

                    face1.vertices.push_back(vert1);

                    vert1.x = vertices[idx_fv_3 - 1].x;
                    vert1.y = vertices[idx_fv_3 - 1].y;
                    vert1.z = vertices[idx_fv_3 - 1].z;

                    face1.vertices.push_back(vert1);

                    faces_of_triangles.push_back(face1);
                    
                //} 
            }

        }

        file.close(); // closing file        
    }

    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

}

void Obj_reader :: print_file()
{
    std::ofstream outfile;
    outfile.open("output.stl"); //opening file to write
   
    if (!outfile) // file couldn't be opened
    { 
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }

         outfile << "solid" << std::endl;

    for(int i = 0; i < faces_of_triangles.size(); i++)
    {
        outfile << "\tfacet normal " << faces_of_triangles[i].face_normals.i << " " << faces_of_triangles[i].face_normals.j << " " << faces_of_triangles[i].face_normals.k <<"\n" ;
        outfile << "\t\touter loop" << "\n";

        outfile <<"\t\t\tvertex " << faces_of_triangles[i].vertices[i].x << " " << faces_of_triangles[i].vertices[i].y << " " << faces_of_triangles[i].vertices[i].z <<"\n";
        outfile <<"\t\t\tvertex " << faces_of_triangles[i].vertices[i+1].x << " " << faces_of_triangles[i].vertices[i+1].y << " " << faces_of_triangles[i].vertices[i+1].z <<"\n";
        outfile <<"\t\t\tvertex " << faces_of_triangles[i].vertices[i+2].x << " " << faces_of_triangles[i].vertices[i+2].y << " " << faces_of_triangles[i].vertices[i+2].z <<"\n";
        outfile << "\t\tendloop" << std::endl;
        outfile << "\tendfacet" << std::endl;

    } 
        outfile << "endsolid" << std::endl;
    
    outfile.close();

}

int main()
{
    Obj_reader obj1;

    obj1.read_obj_file();
    obj1.print_file();
}