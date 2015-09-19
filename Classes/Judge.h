//
//  Judge.h
//  
//
//  Created by 鶴貝康男 on 2015/09/19.
//
//

#ifndef ____Judge__
#define ____Judge__

#include <stdio.h>

#include "Arrangement.h"
#include "fairy.h"

class Judge{
public:
    static void judge(int x, int y);
    static bool judgeDelete(fairy* fairyMale, fairy* fairyFemale);
};


#endif /* defined(____Judge__) */
