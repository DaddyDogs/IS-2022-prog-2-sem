#include "RubiksCube.h"


int main() {
    RubiksCube my_cube;
    my_cube.read("cube_config");
    std::cout << my_cube << "\n";
//    std::vector <std::string> ans;
//    my_cube.first_step(ans);
//    my_cube.second_step(ans);
//    std::cout << my_cube << "\n";
    return 0;
}
