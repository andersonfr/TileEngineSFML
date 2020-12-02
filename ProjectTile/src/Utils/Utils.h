#ifndef _UTILS__H
#define _UTILS__H

#include <string>

#include <vector>
#include <istream>
#include <fstream>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <sstream>

//void LoadTileMapInfo(const std::string& filename, std::vector<std::vector<int>>& result)
//{
//	std::ifstream myFile("grass.csv");
//	if (!myFile.is_open())
//		throw std::runtime_error("could not open file");
//	std::vector<int> t;
//	std::string line, colname;
//	int val;
//	int row, col;
//
//	if (myFile.good())
//	{
//		row = 0;
//		while (std::getline(myFile, line))
//		{
//			std::stringstream ss(line);
//			
//			std::vector<int> temp;
//			while (ss >> val)
//			{
//				//result.at(colIdx).push_back(val);
//				temp.push_back(val);
//				t.push_back(val);
//				if (ss.peek() == ',')
//					ss.ignore();
//			}
//			result.push_back(temp);
//		}
//
//	}
//
//	myFile.close();
//}

void LoadTileMapInfo(const std::string& filename, std::vector<int>& result, int& width, int& height)
{
	std::ifstream myFile(filename);
	if (!myFile.is_open())
		throw std::runtime_error("could not open file");
	std::vector<int> t;
	std::string line, colname;
	int val;
	int colCount = 0;

	if (myFile.good())
	{
		
		while (std::getline(myFile, line))
		{
			std::stringstream ss(line);
			colCount = 0;
			while (ss >> val)
			{
				result.push_back(val);
				if (ss.peek() == ',')
					ss.ignore();
				colCount++;
			}
			height++;
		}

	}
	width = colCount;
	myFile.close();
}

#endif


