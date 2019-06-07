/*================================================================
*   Copyright (C) 2019 Lynxi Ltd. All rights reserved.
*   
*   @file       ：vectorTest.cpp
*   @author     ：afly
*   @date       ：2019.06.07
*   @description：
*
*================================================================*/



/**
*@param a     :
*@param b     :
*@retval      :
*@brief       :
*/

#include <iostream>
#include "vectorTest.h"
#include <vector>
#include <array>

using namespace std;
void vectorTest(){

    std::vector <int> vi;
    vi.reserve(1000);
    for(int i=0;i<1000;i++)
    {
        vi.push_back(i);   
    }
    size_t capa = vi.capacity();
    cout<<"capa = "<<dec<<capa<<endl;
    cout<<"ele = "<<dec<<vi.at(999)<<endl;

    for(std::vector<int>::iterator it = vi.begin(); it != vi.end();it++)
    {
        cout<<*it<<endl;
    }

    array<string, 5> words {"one", "two","three", "four", "five"};
    array<string, 5> words1 {"one1", "two1","three1", "four1", "five1"};
    vector<string> words_copy {begin(words) , end(words)};
    
    cout<<"words_copy = "<<words_copy.at(0)<<endl;


    const int size = 7; 
    int ia[size] = { 0, 1, 1, 2, 3, 5, 8 }; 
    vector<int> ivec(size);

    /* 
    当我们用一个给定的大小定义一个 vector 时，例如 ： 
    vector ia( 10 ); 
    任何一个插入操作都将增加vector 的大小，而不是覆盖掉某个现有的元素，这看起来好像是很显然的，但是 下面的错误在初学者中并不少见 ： 
    size 从7变成了14
   */

    for( int ix = 0; ix < size; ++ix ) 
        ivec.push_back(ia[ix]); 
    for(std::vector<int>::iterator it = ivec.begin(); it != ivec.end();it++)    
        cout<<*it<<endl;

    //二维数组
    vector<vector<int>> matrix(20);     

    for(int i = 0; i < 20; i++) 
    { 
        for(int j = 0; j < 10; j++) {
            matrix[i].push_back(i*j);
        }
    }    
    for(int i=0; i< matrix.size(); i++)//输出二维动态数组 
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    int N=5, M=6; 
    vector<vector<int>> matirx56(N, vector<int>(M)); //定义二维动态数组5行6列 
 

}

