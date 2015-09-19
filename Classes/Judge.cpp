//
//  Judge.cpp
//  
//
//  Created by 鶴貝康男 on 2015/09/19.
//
//

#include "Judge.h"

void judge::judge(int x, int y)
{
    bool ret_left;
    bool ret_right;
    bool ret_up;
    
    ret_left = judgeDelete(fairys[x][y], fairys[x-1][y]);//左の妖精とのマッチング判定
    ret_up = judgeDelete(fairys[x][y], fairys[x][y-1]);//上の妖精とのマッチング判定
    ret_right = judgeDelete(fairys[x][y], fairys[x+1][y]);//右の妖精とのマッチング判定

    if (ret_left || ret_up || ret_right) {
        fairys[x][y].kill();
    }
    
    if (ret_left) {
        fairys[x-1][y].kill();
        Arrangement.arrangement(x-1, y);
    }
    
    if (ret_up) {
        fairys[x][y-1].kill();
    }
    
    if (ret_right) {
        fairys[x+1][y].kill();
        Arrangement.arrangement(x+1, y);
    }
    

    //左右の妖精とのマッチングが成立した時は、その下に妖精がいた場合の整理メソッドを呼び出し
    
}

bool Judge::judgeDelete(fairy* fairyMale, fairy* fairyFemale)
{
    bool flag;
    
    if (fairyMale.getType(); == fairyFemale.getType()) {
        flag = true;
    } else {
        flag = false;
    }
    
    return flag;
}
