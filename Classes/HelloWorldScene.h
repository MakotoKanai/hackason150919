#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "const.h"
#include "fairy.h"


class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
public:
	/// MakotoKanai work ////////////
	static const int fairyTableWidth  = 5;
	static const int fairyTableHeight = 10;

	Fairy fairy[fairyTableWidth][fairyTableHeight];
	
	float passedTime;
	bool isGameOver;
	unsigned int score;
	float lastIncreese;

	float tableOriginX;
	float tableOriginY;

	// methods
	void gameInit();

	void update(float time);
	  	Fairy&& createFairy(int type, float fx, float fy);
	Fairy&& createFairy(int type, int ix, int iy);

	/// MakotoKanai work ////////////


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
