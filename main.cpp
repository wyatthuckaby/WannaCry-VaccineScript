#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;


void run (string filename){
	string command = "start powershell.exe ";
	command += filename;

	system(command.c_str());
}
bool vaccinateExists(string file){
	ifstream t(file);
	return t.is_open();
}
int main (int argc, char *argv[]){

    string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string scText[] = {
		"Set-SmbServerConfiguration -EnableSMB1Protocol $false -Force\n",
		"sls EnableSMB1Protocol Get-SmbServerConfiguration -ca \n"
	};

	//generate a file name to prevent selective exploits.
	string filename = "";
	for (int i = 0; i < 15;  i++){
		filename += alphanum[rand() % (alphanum.length())];
	}
	filename+=".ps1";
	//ofsteam create nonsense

	if (vaccinateExists(filename)){
		ofstream script (filename.c_str());


		script << scText[0];
		script << scText[1];

		system ("start powershell.exe Set-ExecutionPolicy RemoteSigned \n");
		run(filename.c_str());


	} else{
		cout  << "Script file either corrupt or no longer signed to be safe. Please submit issue with us:" << endl;
		cout  << "https://github.com/pnelego/WannaCry-VaccineScript/issues" << endl;
		cout <<  "Press any key to exit" << endl;
		cin.get();
	}
	return 0;
}
