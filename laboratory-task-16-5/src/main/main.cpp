#include "../Student/Student.hpp"
#include <vector>
#include <fstream>
#include <algorithm>


void printVector(std::vector<Student> arr, std::ostream& fout = std::cout)
{
	for (Student& i : arr)
	{
		fout << i;
	}
}


int main()
{
	std::vector<Student>arr;
	Student temp;
	std::ifstream fin("src/files/Students.txt");

	while (fin >> temp)
	{
		arr.push_back(temp);
	}
	fin.close();

	std::sort(arr.begin(), arr.end(), [](const Student& a, const Student& b) {return strcmp(a.name.c_str(), b.name.c_str()) < 0; });
	
	std::ofstream fout("src/files/Fio.txt");
	printVector(arr, fout);
	fout.close();

	std::sort(arr.begin(), arr.end(), [](const Student& a, const Student& b) {if (a.course == b.course) { if (a.group == b.group) { return strcmp(a.name.c_str(), b.name.c_str()) < 0; } return a.group < b.group; } return a.course < b.course; });
	
	fout.open("src/files/Groups.txt");
	printVector(arr, fout);
	fout.close();

	return 0;
}
