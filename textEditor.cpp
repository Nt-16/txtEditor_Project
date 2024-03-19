#include<iostream> // for geting input and output 
#include <stdio.h>
#include <fstream> 
#include <cstdlib>
#include <string>



using namespace std;
//declaring the function so that other function can access it
void create_new_file();
void printMenu();
void read_file();
void empting_file();
void delete_file();

// global varaiable

string filename; // stores the user input of the file name
string text; // 
string line; // stores the actual content that goes in the file



// creating different functions to handle each opearation.

void printMenu(){

    cout << " Welcome to Text Editor"<<endl;
    cout << " __________________________"<< endl;
    cout << "1. Create a new file. "<< endl;
    cout << "2. Read from a file. "<< endl;
    cout << "3. Empty a file. "<< endl;
    cout << "4. Delete a file. "<< endl;
    cout << "5. Copy a file. "<< endl;
    cout << "6. Exit "<< endl;

}


void handle_user_order(){
    int input = 0; // stores user input number
    cout<<endl<< "Enter you choice(1 to 7): " <<" ";
    cin>> input;
    cout<< endl; // adding a line 

    if (input == 1){
        create_new_file();
        
    } 
    if ( input == 2){
        read_file();
        // call function to add to a file 
    }
    if ( input == 3){
        empting_file();
        // call function to empty to a file 
    }
    if ( input == 4){
        delete_file();
        // call function to delete to a file 
    }

    if ( input == 5){
        // call function to delete to a file 
    }
    if ( input == 6){
        // call function to exit the program   
    }

  
}
// void result_messsage(int num)
// {
//     if (num == 1)
//     {
//         cout <<" File has been sucessfully created "
//     }
// }
void create_new_file(){
    
    cout << "Enter the name of file: " << " ";
    
    cin.ignore(); // removing the buffering memory of cin 
    getline(cin, filename);

    ofstream myfile((filename + ".txt").c_str()); //
    cout << endl<< " Enter text to write into file: (Enter 'END' to complete)"<< endl;
    myfile.open((filename + ".txt").c_str(), ios::app);

    cin.ignore();

    while(getline(cin, line)) // logic for when to stop reading the text
    {
        if (line.size() >= 3)
        {
            if (line.substr(line.size()-3) == "END")
            {
                text += line.substr(0, line.size()-3);
                break;
            }
            else
            {
                text += line+"\n";

            }
        }
        else{
            text += line+"\n";

        }
    }
    myfile<< text;
    myfile.close();
    
    cout << "New file was successfully created. "<< endl;

}


void read_file()
{
    cout<< endl<< "Enter the name of the file: "<< " ";

    cin >> filename;
    fstream myfile;

    myfile.open((filename+".txt").c_str());

    while (getline(myfile,text))
    {
        cout << text <<"\n";
    }
    myfile.close();

}

void delete_file(){
    cout<< endl<< "Enter filename to delete: "<< " ";
    cin >> filename;
    remove((filename+".txt").c_str());


}

//function to remove the content of the file.
void empting_file() 
{
    cout<< endl<< "Enter the name of the file: "<< " ";
    cin >> filename;

    ofstream myfile;
    myfile.open((filename+".txt").c_str());
    myfile << "";
    myfile.close();

}

void copying_file(){
    
}


int main (){

    printMenu(); // printing the prompts to the users
    handle_user_order();




    return 0;
}