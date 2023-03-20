#include "array_access.hpp"
#include "qdebug.h"

array_access::array_access(int line, int col, expression *array, expression *index, std::string func)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index;
    Funcion = func;
}

symbol array_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol symInd (Line,Col,"",NULO,nullptr);
    symbol symArr = Array->ejecutar(env, tree);
    if(Index != nullptr)symInd = Index->ejecutar(env, tree);

    if(Funcion == "size"){
      QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
      int *val = (int *)Arr->size();
      sym = symbol(Line,Col,"",INTEGER,&val);
      int *a = new int;
      *a = *static_cast<int*>(sym.Value);
      sym.Value = a;
    }
    else if(Funcion == "mean"){
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        if (symArr.Tipo == INTEGER || symArr.Tipo == VECTOR) {
            int *suma = new int;
            *suma = 0;
            for (int i = 0; i < Arr->size(); ++i) {
              *suma += *static_cast<int*>(Arr->at(i).Value);
//                qDebug() << *suma;
            }
            float average = (float)*suma/Arr->size();
//            std::cout<<"Suma es: "<<*static_cast<int*>(suma)<<std::endl;
//            std::cout<<"MEDIA es: "<<average<<std::endl;
            float *a = new float;
            sym = symbol(Line,Col,"",FLOAT,&average);
            *a = *static_cast<float*>(sym.Value);
            sym.Value = a;
            return sym;
        }else{
            tree->ErrorOut+="Error: Tipo de vector incorrecto para MEDIA";
        }
    }
    else if(Funcion == "moda"){
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        // Crear un map para contar las veces de cada valor
        std::unordered_map<int, int> freq;
        for (int i = 0; i < Arr->size(); i++) {
            // Convertir el valor de tipo void* a int
            int val = *reinterpret_cast<int*>((*Arr)[i].Value);
            freq[val]++;
        }
        // Encontrar el valor con la mayor cantidad de ocurrencias
        int max_freq = 0;
        void* moda = nullptr;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second > max_freq) {
                max_freq = it->second;
                moda = reinterpret_cast<void*>(new int(it->first));
            }
        }
        int result = *static_cast<int*>(moda);
        int *a = new int;
        sym = symbol(Line,Col,"",INTEGER,&result);
        *a = *static_cast<int*>(sym.Value);
        sym.Value = a;
        return sym;
    }
    else if(Funcion == "median"){
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        std::vector<int> valores;
//        Ingresar los valores en un array de tipo int
        for(auto objeto : *Arr) {
                int valor_entero = *(int*)(objeto.Value);
                valores.push_back(valor_entero);
            }

    // Ordenar los enteros de forma ascendente
        std::sort(valores.begin(), valores.end());
    // Encontrar la mediana
        float mediana;
        if(valores.size() % 2 == 0) {
            // Si el vector tiene un número par de elementos, la mediana es el promedio de los dos elementos centrales
            int idx_izq = (valores.size() / 2) - 1;
            int idx_der = valores.size() / 2;
            mediana = (valores[idx_izq] + valores[idx_der]) / 2.0;
        } else {
            // Si el vector tiene un número impar de elementos, la mediana es el elemento central
            int idx_central = valores.size() / 2;
            mediana = valores[idx_central];
        }
//         retornar valor
            float *a = new float;
            sym = symbol(Line,Col,"",FLOAT,&mediana);
            *a = *static_cast<float*>(sym.Value);
            sym.Value = a;
    }
    else if (Funcion == "get") {
        //validando tipo array
        if(symArr.Tipo == VECTOR && symInd.Tipo == INTEGER)
        {
            QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
            QVector<symbol> result = *Arr;
            int *val = (int *)symInd.Value;
            if (*val > Arr->size() - 1) {
                tree->ErrorOut+= "Error: INDEX out of range ";
            }else{
                sym = result[*val];
            }

            return sym;
        }
        else {
            tree->ErrorOut+="Error: index incorrecto";
        }
    }
    //validando tipo array
    if(symArr.Tipo == VECTOR && symInd.Tipo == INTEGER)
    {
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        QVector<symbol> result = *Arr;
//        for (int i = 0; i < 3; ++i) {
//            std::cout<<"i:"<<i<<" ="<<*static_cast<int*>(Arr->at(i).Value)<<std::endl;
//        }
        int *val = (int *)symInd.Value;
        sym = result[*val];
    }

    return sym;

}
