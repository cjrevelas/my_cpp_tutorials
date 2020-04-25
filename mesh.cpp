#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::string> tokenize(std::string input_string);

int main(){

    std::cout << "==========================================================" << std::endl;

    //open file to parse and files to write
    std::string filename_1 = "mesh.mphtxt", filename_2 = "meshPoints.txt", filename_3 = "elemCon.txt";
    std::ifstream meshInput;
    std::ofstream meshPoints, elemCon;
    std::vector<std::string> lines_of_input_file;
    std::vector<std::string> tokens;

    std::cout << "Reading file " << filename_1 << " to import COMSOL mesh." << std::endl;

    meshInput.open(filename_1);
    meshPoints.open(filename_2);
    elemCon.open(filename_3);

    if(meshInput)
        std::cout << "COMSOL mesh file opened successfully." << std::endl;


    std::cout << "Started file parsing.." << std::endl;

    //starting file parsing
    while(meshInput.good()){

        std::string current_line;
        getline(meshInput, current_line);

        int ndm, numnp, nen, numel;

        if(current_line.find("sdim") != std::string::npos){
            tokens = tokenize(current_line);
            ndm = atoi(tokens[0].c_str());
            std::cout << "Number of dimensions = " << ndm << std::endl;
            //break;
        }

        if(current_line.find("number of mesh points") != std::string::npos){
            tokens = tokenize(current_line);
            numnp = atoi(tokens[0].c_str());
            std::cout << "Number of meshpoints = " << numnp << std::endl;
            //break;
        }

        if(current_line.find("Mesh point coordinates") != std::string::npos){
            for (int ii=0; ii<numnp; ++ii){
                getline(meshInput, current_line);
                meshPoints << current_line << std::endl;
            }
            //break;
        }

        if(current_line.find("10 0 number of nodes per element") != std::string::npos){
            tokens = tokenize(current_line);
            nen = atoi(tokens[0].c_str());
            std::cout << "Number of nodes per element = " << nen << std::endl;

            getline(meshInput, current_line);
            tokens = tokenize(current_line);
            numel = atoi(tokens[0].c_str());
            std::cout << "Number of elements = " << numel << std::endl;

            getline(meshInput, current_line);

            for(int ii=0; ii<numel; ++ii){
                getline(meshInput, current_line);
                elemCon << current_line << std::endl;
            }
            //break;
        }
}

//close all files and exit the program
std::cout << "Done!" << std::endl;
meshInput.close();
meshPoints.close();
elemCon.close();
std::cout << "==========================================================" << std::endl;

return 0;
}


std::vector<std::string> tokenize(std::string input_string){

    std::string buf;
    std::stringstream ss(input_string);
    std::vector<std::string> tokens;

    while(ss >> buf)
        tokens.push_back(buf);

    return tokens;
}
