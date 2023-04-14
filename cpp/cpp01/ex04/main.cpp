#include <iostream>
#include <fstream>

bool contains(std::string str, const std::string target) {
	return str.find(target) != std::string::npos;
}

std::string replace(std::string str, const std::string target, const std::string source) {
	while (contains(str, target)) {
		int index = str.find(target);
		str.erase(index, target.length());
		str.insert(index, source);
	}
	return str;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error!!" << std::endl;
		return 1;
	}
	const std::string filename = argv[1];
	const std::string target = argv[2];
	const std::string source = argv[3];

	std::ifstream readFile;
	std::string temp;
	std::string desc;
	std::string res;
	
	readFile.open(filename);

	if (readFile.is_open()) {
		//TODO: 빈 파일, 처음부터 개행, 공백 오는거 고려해볼 것.
		while (getline(readFile, temp)) {
			desc.append(temp);
			desc.append("\n");
		}
		desc.pop_back();
		res = replace(desc, target, source);
		readFile.close();
	} else {
		std::cout << "Can't open file" << std::endl;
		return 1;
	}

	std::ofstream outFile(filename + ".replace");
	if (outFile.is_open()) {
		outFile << res;
	} else {
		std::cout << "Can't create file" << std::endl;
		return 1;
	}
}