#ifndef PICROSS_H
#define PICROSS_H

#include <vector>
#include <SFML/Graphics.hpp>

class Picross {
    public:
        Picross(std::vector<std::vector<int>> _x_constraints, std::vector<std::vector<int>> _y_constraints);
        
        //Provides a single iteration of solving the picross puzzle.
        void iterate();

        //Solves the picross puzzle.
        void solve();

        std::vector<std::vector<int>> getAns();

    private:
        std::vector<std::vector<int>> x_constraints;
        std::vector<std::vector<int>> y_constraints;
        std::vector<std::vector<int>> ans;
};

#endif