#include <iostream>
#include <fstream>
#include <vector>

int convert(std::string filein)
{
    std::ifstream fin;
    fin.open(filein);

    std::vector<std::vector<float>> vertices;
    std::vector<std::pair<int,int>> links;

    std::string wire_thickness = "8.000e-04";

    std::string line;
    while(fin>>line)
    {
        std::cout<<line<<"\n";

        if(line[0] == 'v') //in .obj files 'v' marks a line that describes a vertex
        {
            float x,y,z = 0;
            fin>>x;
            fin>>y;
            fin>>z;

            std::vector<float> vertex;
            vertex.resize(3);

            vertex[0] = x;
            vertex[1] = y;
            vertex[2] = z;

            vertices.push_back(vertex);
        }
        if(line[0] == 'l') //'l' marks a line between two vertices
        {
            std::pair<int,int> link;
            fin>>link.first;
            fin>>link.second;

            links.push_back(link);
        }
    }

    fin.close();

    for(int i = 1; i <= vertices.size(); i++)
    {
        std::cout<<i<<" "<<vertices[i-1][0]<<" "<<vertices[i-1][1]<<" "<<vertices[i-1][2]<<"\n";
    }

    for(int i = 1; i <= links.size(); i++)
    {
        std::cout<<i<<" "<<links[i-1].first<<" "<<links[i-1].second<<"\n";
    }

    std::ofstream fout;
    fout.open("result.maa");
    
    //boilerplate text that is on top of a .maa file

    fout<<"\n*\n0.0\n***Wires***\n";
    
    fout<<links.size()<<"\n"; //the amount of links between vertices is the amount of wires in the antenna project

    for(int i = 0; i < links.size(); i++) //defines the wires in the file
    {
        int first_vertex,second_vertex;
        first_vertex = links[i].first;
        second_vertex = links[i].second;

        /*
        MMANA save files save wires as: x1, y1, z1, x2, y2, z2

        Blender exported .obj files save vertices as x,z,-y (compared to in-blender coordinates)
        and then there is a separate list of links between vertices
        */


        //we invert the y coordinate of the blender export
        //vertices[first_vertex-1][2] = -1 * vertices[first_vertex-1][2];
        //vertices[second_vertex-1][2] = -1 * vertices[second_vertex-1][2];

        fout<<vertices[first_vertex-1][0]<<","<<(char)9<<vertices[first_vertex-1][2]<<","<<(char)9<<vertices[first_vertex-1][1]<<","<<(char)9;
        //-1 because we count from 0 or smth

        fout<<vertices[second_vertex-1][0]<<","<<(char)9<<vertices[second_vertex-1][2]<<","<<(char)9<<vertices[second_vertex-1][1]<<","<<(char)9;

        fout<<wire_thickness<<","<<(char)9<<"0\n";
    }

    // more boiler plate at the bottom

    fout<<"***Source***\n";
    fout<<"0,"<<(char)9<<"0\n";
    fout<<"***Load***\n";
    fout<<"0,"<<(char)9<<"0\n";
    fout<<"***Segmentation***\n";
    fout<<"800,"<<(char)9<<"80,"<<(char)9<<"2.0,"<<(char)9<<"2\n";
    fout<<"***G/H/M/R/AzEl/X***\n";
    fout<<"0,"<<(char)9<<"0.0,"<<(char)9<<"0,"<<(char)9<<"50.,"<<(char)9<<"120,"<<(char)9<<"60,"<<(char)9<<"0.0\n";
    fout<<"###Comment###\n";
    fout<<"Converted to .maa by software made by SP6NEO";

    fout.close();

    return 0;
}