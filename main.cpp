#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

class Csv{
	string filePath;

	void promptLine(vector<string> lineColumns){
		for (const auto& x : lineColumns) {

	        	cout << x << " " ;

		}
	}
	vector<string> processLine(string line){
		vector<string> tokens;
		stringstream ss(line);
		string token;
		while (getline(ss, token, ',')) {
			tokens.push_back(token);
		}
		return tokens;
	}

	void readCsv(){
		string line;
		ifstream StreamReadCSVFile(filePath);
		while(getline(StreamReadCSVFile, line)){	
			vector<string> processedLine = processLine(line);
			promptLine(processedLine);
			cout << endl;
		}
	}

	public:
		Csv(string x){
			filePath = x;
			readCsv();
		}
};
			
int main(int argc, char* argv[]){
	Csv csvObj(argv[1]);
	return 0;
}
