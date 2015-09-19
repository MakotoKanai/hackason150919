//
//  Arrangement.cpp
//  
//
//  Created by 鶴貝康男 on 2015/09/19.
//
//

#include "Arrangement.h"

void Arrangement::arrangement(int x, int y)
{
    
    if (fairys[x][y+1]->isAlive){
        arrangementMove(x, y+1);
        //マッチング成立した妖精の下の妖精が居る場合、移動メソッドを呼び出し
    } else {
        break;
    }
    
}

void Arrangement::arrangementMove(int x, int y)
{
    for (int i = 0; fairys[x][y+i]->isAlive(); i++) {
        animation();
    }//下に妖精がいる限り、上に1つ移動するアニメーションを呼び出し
    
}