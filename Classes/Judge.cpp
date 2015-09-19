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
    ret_right = judgeDelete(fairys[x][y], fairys[x][y-1]);//上の妖精とのマッチング判定
    ret_up = judgeDelete(fairys[x][y], fairys[x+1][y]);//右の妖精とのマッチング判定
    
    fairys[x-1][y]->is_arrive = ret_left;
    fairys[x][y-1]->is_arrive = ret_up;
    fairys[x+1][y]->is_arrive = ret_right;
}

bool Judge::judgeDelete(Fairy* fairyMale, Fairy* fairyFemale)
{
    bool flag;
    
    if (fairyMale->id == fairyFemale->id) {
        flag = true;
    } else {
        flag = false;
    }
    
    return flag;
}
