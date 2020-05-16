class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        float slope =get_slope(coordinates[0], coordinates[1]);
        for(int i =2; i< coordinates.size(); ++i){
            float m = get_slope(coordinates[i], coordinates[0]);
            if(m!= slope)
                return false;
        }
        return true;
    }
    float get_slope(vector<int>& p1, vector<int>& p2){
        if(p1[0]==p2[0])
            return 100000;
        return(float)(p2[1] - p1[1])/(p2[0] -p1[0]);

    }
    }
};

// #include <iostream>
// #include <vector>
// #include <sstream>

// using namespace std;

// float get_slope(vector<int> &p1, vector<int> &p2)
// {
//     if (p1[0] == p2[0])
//         return 100000;
//     return (float)(p2[1] - p1[1]) / (p2[0] - p1[0]);
// }

// bool checkStraightLine(vector<vector<int>> &coordinates)
// {
//     float slope = get_slope(coordinates[0], coordinates[1]);
//     for (int i = 2; i < coordinates.size(); ++i)
//     {
//         float m = get_slope(coordinates[i], coordinates[0]);
//         if (m != slope)
//             return false;
//     }
//     return true;
// }

// //int main(int argc, char **argv)   //these are commandline arguement

// int main()
// {

//     std::string line;
//     int number;
//     std::vector<int> numbers;
//     std::vector<vector<int>> co;

//     std::cout << "Enter numbers separated by spaces: ";
//     std::getline(std::cin, line);
//     std::istringstream stream(line); //istringstream is datatype
//     // while (stream >> number)
//     //     numbers.push_back(number);

//     while (stream >> number)
//     {
//         int n2 = 0;

//         stream >> n2;
//         numbers.push_back(number);
//         numbers.push_back(n2);
//         co.push_back(numbers);
//     }
//     checkStraightLine(co);
//     get_slope(numbers, numbers);
// }