#pragma once
#include "pch.h"

class Material {

private:

public:
    std::string m_name;
    int m_id;
    int m_weight;
    int m_velocity;
    int m_hardness;
    int m_health;
    bool m_hasbeenupdated;
    bool isfreefalling;
    Material(std::string name, int id);
    void gravity(std::vector<std::vector<int>>& matrix, int i, int j);
    void updatematerial(std::vector<std::vector<int>>& matrix, int i, int j);
};
