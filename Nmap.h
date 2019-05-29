#ifndef NMAP_H_
#define NMAP_H_
/*
1 填满整个地图
2 地图上随机挖一个洞
3 选中某一房间的墙壁
4 随机新建某种元素
5 查看从选中的墙延伸出去有足够的空间来放新元素
6 有 继续  不然返回 3
7 从选中的墙面增加新元素
8 返回 3 直到地图建设完成
9 随机放置出入口 
10 放入随机物品...
*/
#include <random>
#include <vector>
#include <iostream>
int Map[32][32];
using namespace std;
void Print_Rect(int width,int length){
    for (int i = 0; i < width; i++)
    {
        if(i==0||i==width-1)
        {
            for (int i = 0; i < length; i++)
                cout << "*";
        }
        else
        {      
            for (int i = 0; i < length-1 ; i++)
            {
                if (i == 0 || i == length-1){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            cout << "*";
        }
        cout << endl;
    }
}
void Print_Rhombus(int line){
    int Line1 = line / 2;
    if (Line1 % 2 == 0)
        Line1++;
    int Length = (line * 2 - 1);
    int Mid = Length / 2;
    for (int i = 1; i < line; i++){
        if(i==0||i==1){
            continue;
        }
        else if(i==2){
            for (int j = 0; j < Length; j++){
                if(j==Mid-2||j==Mid-1||j==Mid)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
        else{
            for (int j = 0; j < Length; j++){
                if (j == (Mid - i) || j == (Mid+i-2)){
                    cout << "*";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }//half rhombus
    for (int i = 0; i < Length; i++){
        if(i==0||i==Length-3){
            cout << "*";
        }
        else
            cout << " ";
    }
    cout << endl;
    for (int i = line-1; i > 1; i--){
        if(i==0||i==1){
            continue;
        }
        else if(i==2){
            for (int j = 0; j < Length; j++){
                if(j==Mid-2||j==Mid-1||j==Mid)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
        else{
            for (int j = 0; j < Length; j++){
                if (j == (Mid - i) || j == (Mid+i-2)){
                    cout << "*";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}
void Print_Road(string choose){
    if(choose=="Row"||choose=="row"){
        for (int i = 0; i < 5;i++){
            cout << "*";
        }
    }
    else if(choose=="Columu"||choose=="columu"){
        for (int i = 0; i < 5;i++){
            cout << "*\n";
        }
    }
}


#endif