//
//  Animation.cpp
//  
//
//  Created by 鶴貝康男 on 2015/09/19.
//
//

#include "Animation.h"

void move(cocos2d::Sprite* sprite)
{
    auto animation = MoveBy::create(2, Vec2(0,-1));
    sprite->runAction(animation);
}