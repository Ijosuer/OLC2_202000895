#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include <map>
#include "Environment/ast.hpp"
#include "Environment/symbol.hpp"
#include "Environment/func_symbol.hpp"
using std::map;

class environment
{
public:
    environment *Anterior;
    bool flagmine =false;
    map<std::string, symbol> Tabla;
    std::string Id;
    map<std::string, func_symbol> TablaFunctions;
    map<std::string, map<std::string, TipoDato>> TablaStructs;
    environment(environment *back,std::string id);
    void SaveVariable(symbol sym, std::string id, ast *tree);
   void SaveStruct(map<std::string, TipoDato> tabla, std::string id, ast *tree);
    void SaveFunc(func_symbol sym, std::string id, ast *tree);
    symbol GetVariable(std::string id,environment *env, ast *tree);
    func_symbol GetFunc(std::string id, environment *env, ast *tree);
    void ActualizarVariable(std::string id,environment *env, symbol valor ,ast *tree);
    void aument(std::string id,environment *env, std::string operador ,ast *tree);
    map<std::string, TipoDato> GetStruct(std::string id, environment *env, ast *tree);
};

#endif // ENVIRONMENT_HPP
