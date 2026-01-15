#include<iostream>
#include<fstream>
#include<regex>
#include<string>

void transpile(std::string filename){
    std::ifstream in(filename);
    std::ofstream out("output.cpp");

    if(!in.is_open()){
        std::cerr << "Could not open: " << filename << std::endl;
        exit(1);
    }

    out << "#include<iostream>\n";
    out << "using namespace std;\n";
    out << "int main(){\n";

    std::string line;
    int indent = 1;

    auto writeIndent = [&](int level){
        for (int i = 0; i < level; i++) out << "    ";
    };

    while (std::getline(in  , line)){
        std::string origional  = line;

        // trim spaces
        line = std::regex_replace(line, std::regex("^ +| +$"), "");

        // If there is nothingon the line we can just skip it 
        if(line.empty()) continue;

        // Comments in our language start with #
        if(line.rfind("#", 0) == 0){
            std::string comment = line.substr(1);
            writeIndent(indent);
            out<<"// "<< comment << std::endl; 
            continue;
        };

        // number var decleration
        if(line.rfind("num ", 0) == 0){
            line = line.substr(4);
            writeIndent(indent);
            out << "int " << line << ";" << std::endl;  
            continue;
        }
     
        // decimal var decleration
        if(line.rfind("decimal ", 0) == 0){
            line = line.substr(8);
            writeIndent(indent);
            out << "double " << line << ";" << std::endl;  
            continue;
        }
     
        // character var decleration
        if(line.rfind("letter ", 0) == 0){
            line = line.substr(7);
            writeIndent(indent);
            out << "char " << line << ";" << std::endl;  
            continue;
        }
     
        // Print statement 
        if(line.rfind("print ", 0) == 0){
            // 5 for print and sixth for the (
            std::string expression = line.substr(6);
            writeIndent(indent);
            out<< "cout<<" << expression << " << endl;" << std::endl;
            continue;
        }

        // Input statement
        if(line.rfind("input ", 0) == 0){
            std::string variable = line.substr(6);
            writeIndent(indent);
            out << "cin >> " << variable << "; " <<std::endl;
            continue;
        }

        // IF condition
        if(line.rfind("if ", 0) == 0){
            // 2 for if and 3rd for " "
            std::string condition = line.substr(3);
            if(condition.back() == '{') condition.pop_back();
            writeIndent(indent);
            
            // write to the output stream
            out << "if(" << condition << "){" << std::endl;
            indent++;
            continue;
        }

        // Else statement for the conditional  
        if(line.rfind("else ", 0) == 0){
            writeIndent(indent);
            out<<"else {" << std::endl;
            indent++;
            continue;
        }

        // Closing brackets for loop and if else conditional and while loops 
        if(line == "}"){
            indent--;
            writeIndent(indent);
            out << "}" << std::endl;
            continue;
        }

        // Loops....
        if(line.rfind("repeat ", 0) == 0){
            std::string condition = line.substr(6);

            // Check for the ending brackets 
            if(!condition.empty() && condition.back() == '{'){
                condition.pop_back(); // Remove the ending brakets...
            }

            writeIndent(indent);
            out << "while("<<condition<<") {" << std::endl;
            indent++;
            continue;
        }

        // Assignment 
        if(line.find("=") != std::string::npos){
            writeIndent(indent);
            out<< line << ";" << std::endl;
            continue;
        }

    }

    // close program
    writeIndent(indent);
    out << "return 0;\n";
    out << "}\n";

    out.close();
    out.flush();

    // Succesfull transpiling...
    std::cout << "[Success] Transpiling complete. See output.cpp\n";
}

void compile_n_run(){
    int compileResult = std::system("g++ output.cpp -o app.exe");

    if(compileResult == 0){
        std::cout << "[Success] Compilation complete. Running now\n";
        std::system(".\\app.exe");
    } else {
        std::cerr << "[Error] Compilation failed!" << std::endl;
    }
}

// argc is the arguments count while argv[] is the argument values...
int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cerr << "Usage: minilang.exe filename.minilang" << std::endl;
    }

    transpile(argv[1]);
    compile_n_run();

    return 0;
}