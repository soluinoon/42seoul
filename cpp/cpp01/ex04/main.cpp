#include <iostream>
#include <fstream>

bool contains(std::string str, const std::string target) {
	std::cout << "str = " << str << std::endl;

	std::cout << str.find(target) << std::endl;
	std::cout << std::string::npos << std::endl;
	return str.find(target) != std::string::npos;
}
// bbb
// bbb
std::string replace(std::string str, const std::string target, const std::string source) {
	while (contains(str, target)) {
		int index = str.find(target);
		std::cout << "start" << std::endl;
		std::cout << str.erase(index, target.length()) << std::endl;
		std::cout << str.insert(index, source) << std::endl;
		std::cout << "catch!! : " << index << std::endl;
	}
	std::cout << "str[0] : " << str[0] << std::endl;
	std::cout << "str[1] : " << str[1] << std::endl;
	std::cout << "str[2] : " << str[2] << std::endl;

	return str;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error!!" << std::endl;
		return 1;
	}
	const std::string filename = argv[1];
	std::cout << "filename" << std::endl;
	std::cout << filename << std::endl;
	const std::string target = argv[2];
	std::cout << "target" << std::endl;
	std::cout << target << std::endl;
	const std::string source = argv[3];
	std::cout << "source" << std::endl;
	std::cout << source << std::endl;

	std::ifstream readFile;
	std::string temp;
	std::string desc;
	std::string res;
	
	readFile.open(filename);

	if (readFile.is_open()) {
		//TODO: 빈 파일, 처음부터 개행, 공백 오는거 고려해볼 것.
		while (getline(readFile, temp)) {
			std::cout << "in" << std::endl;
			desc.append(temp);
			std::cout << "temp= " << temp << std::endl;
			desc.append("\n");
		}
		if (temp[(int)temp.length() - 1] != '\n') {
			desc.pop_back();
		}
		std::cout << "desc = " << desc << std::endl;
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