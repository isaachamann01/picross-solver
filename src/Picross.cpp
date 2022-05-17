#include "Picross.h"

Picross::Picross(std::vector<std::vector<int>> _x_constraints, std::vector<std::vector<int>> _y_constraints){
    x_constraints = _x_constraints;
    y_constraints = _y_constraints;

    //Initialize our answer array to zero.
    for (auto i : x_constraints) {
        std::vector<int> temp(y_constraints.size(),0);
        ans.push_back(temp);
    }
}

void Picross::solve() {
    //First we look at rows individually.


}

void Picross::iterate() {

}

std::vector<std::vector<int>> Picross::getAns() {
    return ans;
}